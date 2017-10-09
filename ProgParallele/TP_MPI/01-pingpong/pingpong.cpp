#include <iostream> // cout, cin
#include <stdlib.h> // srand(), rand()
#include "mpi.h"

using namespace std;

// Ranks
const int MASTER_RANK = 0;
const int SLAVE_RANK = 1;

// Tags
const int MTOS_TAG = 10;
const int STOM_TAG = 11;
const int SEND_N_TAG = 12;
const int SEND_M_TAG = 13;

int main(int argc, char *argv[]) {

	int nprocs, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == MASTER_RANK) {
	
		// Values input by user, only visible to
		// rank 0 at start
		int iN, iM = 0;
	
		for(int i=0; i < argc ; i++) {
	
			if(strcmp("pingN", argv[i]) == 0) {
				sscanf(argv[i+1], "%d", &iN);
			}
			if(strcmp("pingM", argv[i]) == 0)	{
				sscanf(argv[i+1], "%d", &iM);
			}
		}

		if((iM == 0) || (iN == 0)){
			cout << endl <<"Please enter the number of floats to be sent: " ;
			cin >> iN;
			cout << endl << "Please enter how many times the messages are to be sent again: ";
			cin >> iM;
			cout << iN << " floats will be sent " << iM <<" times." << endl;
		}

		// Generate the randon numbers
		srand(time(NULL) + rank);
		float * sendArray = new float[iN];
		float * receiveArray = new float[iN];
		for(int i=0; i < iN; i++) {
			sendArray[i] = rand() % 100;
		}

		double t0 = MPI_Wtime();

		//cout << endl << "Sending number of floats to slave ..." << endl;
		// First send the number of iterations
		MPI_Send(&iN, 1, MPI_INT, SLAVE_RANK, SEND_N_TAG, MPI_COMM_WORLD);
		//cout << "Slave has received the number!" << endl;
		MPI_Send(&iM, 1, MPI_INT, SLAVE_RANK, SEND_M_TAG, MPI_COMM_WORLD);
		//cout << "Slave has received number of iterations." << endl;

		//Envoyer et recevoir M fois
		for(int i = 0; i < iM; i++) {
			MPI_Status status;
			//cout << "About to send floats ..." << endl;
			MPI_Send(sendArray, iN, MPI_FLOAT, SLAVE_RANK, MTOS_TAG, MPI_COMM_WORLD);
			//cout << "floats sent! Wainting for receive..." << endl;
			MPI_Recv(receiveArray, iN, MPI_FLOAT, SLAVE_RANK, STOM_TAG, MPI_COMM_WORLD, &status);
			//cout << "float received!";
		}

		delete[] sendArray;
		delete[] receiveArray;

		double t1 = MPI_Wtime();
		//cout << endl<< "Elapsed WTIME: " << t1 - t0 << " s" << endl;
		cout << iN << "\t";
		cout << iM << "\t";
		cout << t1 - t0 << endl;
	} // rank == MASTER_RANK

	if(rank == SLAVE_RANK) {
		// First receive N
		int recvdN, recvdM;
		MPI_Status status;
		MPI_Recv(&recvdN, 1, MPI_INT, MASTER_RANK, SEND_N_TAG, MPI_COMM_WORLD, &status);
		MPI_Recv(&recvdM, 1, MPI_INT, MASTER_RANK, SEND_M_TAG, MPI_COMM_WORLD, &status);

		// Alloc buffer to receive data
		float * recvBuf = new float[recvdN];
		for(int i = 0; i < recvdM; i++) {
			MPI_Recv(recvBuf, recvdN, MPI_FLOAT, MASTER_RANK, MTOS_TAG, MPI_COMM_WORLD, &status);
			MPI_Send(recvBuf, recvdN, MPI_FLOAT, MASTER_RANK, STOM_TAG, MPI_COMM_WORLD);
		}
	} // rank == SLAVE_RANK 
	

	MPI_Finalize();

}
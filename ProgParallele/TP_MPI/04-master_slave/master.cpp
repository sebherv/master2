#include "common.h"
#include <iostream> // cout, cin
#include <stdlib.h> // srand(), rand()
#include "mpi.h"

using namespace std;

int main(int argc, char *argv[]) {

	int nprocs, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// Init seed
	srand(time(NULL));

	int num = 0;
	int numToSend = 0;
	int numOfSlavesToStop = nprocs - 1;

	cout << "Please enter the number of numbers to be sent: ";
	cin >> num;
	numToSend = num;

	// Signal to slaves that we are ready to proceed
	MPI_Barrier(MPI_COMM_WORLD);

	bool hasToContinue = true;

	while(numOfSlavesToStop > 0) {
		float toSend;
		MPI_Status status;
		MPI_Recv(NULL, 0, MPI_FLOAT, MPI_ANY_SOURCE, TAG_REQUEST_NUMBER, MPI_COMM_WORLD, &status);

		// Retrieve sender
		int targetRank = status.MPI_SOURCE;

		if(num > 0) {
			toSend = (float)rand()/RAND_MAX; // rand between 0.0 and 1.0
			num--;
		} else {
			toSend = -1.0;
			numOfSlavesToStop--;
		}

		MPI_Send(&toSend, 1, MPI_FLOAT, targetRank, TAG_SEND_NUMBER, MPI_COMM_WORLD);

	}

	MPI_Barrier(MPI_COMM_WORLD);

	cout << "Master has finished sending the " << numToSend << " numbers." << endl;

	MPI_Finalize();
}
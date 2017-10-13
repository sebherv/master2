#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "mpi.h"

using namespace std;

const int MASTER_RANK = 0;

const int TAG_RING = 10;


int main(int argc, char *argv[])
{

	int worldSize, rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD,&worldSize);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int inputInt = 0;
	int initRingNum = 0;
	int ringNum = 0;
	int printMsg = 0; // Print by default

	if(rank == MASTER_RANK) {

		// Init rand() seed
		srand(time(NULL));

		//Handle args if possibles
		for(int i=0; i < argc; i++) {
			if(strcmp("numFloats", argv[i]) == 0) {
				sscanf(argv[i+1], "%d", &inputInt);
			}
			if(strcmp("numRings", argv[i]) == 0) {
				sscanf(argv[i+1], "%d", &ringNum);
			}

		}

		if( (inputInt == 0) || (ringNum == 0)) {

			printMsg = 1;
			// Retrieve the numbers
			cout << "Veuillez saisir un nombre entier: " << endl;
			cin >> inputInt;
	
			cout << endl << "Combien de tours effectuer? " << endl;
			cin >> ringNum;
		}
	}

	double t0 = MPI_Wtime();

	// Broadcast the number of times the ring must go round
	MPI_Bcast(&ringNum,1,MPI_INT, MASTER_RANK, MPI_COMM_WORLD);
	initRingNum = ringNum;

	// Broadcast weither we print messages
	MPI_Bcast(&printMsg, 1, MPI_INT, MASTER_RANK, MPI_COMM_WORLD);

	MPI_Barrier(MPI_COMM_WORLD);


	if(rank == MASTER_RANK) {
		// Init the buffer with random values
		float* buffer = new float[inputInt];
		for(int i = 0; i < inputInt; i++) {
			buffer[i] = rand();
		}

		// Send the buffer
		MPI_Send(buffer, inputInt, MPI_FLOAT, 1, TAG_RING, MPI_COMM_WORLD);


		ringNum--;
	}

	while(ringNum > 0) {

		ringNum--;

		// Here all process wait for their next message
		MPI_Status status;
		MPI_Probe(MPI_ANY_SOURCE, TAG_RING, MPI_COMM_WORLD, &status);
		int count;
		MPI_Get_count(&status, MPI_FLOAT, &count);

	
		// Allocate receive buffer
		float * recvBuf = new float[count];
		MPI_Recv(recvBuf, count, MPI_FLOAT, MPI_ANY_SOURCE, TAG_RING, MPI_COMM_WORLD, &status);
		int sender = status.MPI_SOURCE;

		if(printMsg != 0) {
			cout << "Rank " << rank << " has received the following floats ";
			for(int i = 0 ; i < count ; i++) {
				cout << " " << recvBuf[i];
			}
			cout << " from rank " << sender << endl;	
		}
	
		int nextRank = rank + 1;
		bool canSend = true;
		if(nextRank >= worldSize) {
			nextRank = MASTER_RANK;	
			if(ringNum == 0) {
				canSend = false;
			}
		}

		if(canSend) {
			MPI_Send(recvBuf, count, MPI_FLOAT, nextRank, TAG_RING, MPI_COMM_WORLD);
		}

		delete[] recvBuf;
	
	}

	MPI_Barrier(MPI_COMM_WORLD);
	double t1 = MPI_Wtime();


	if(rank == MASTER_RANK) {
		cout << inputInt << " " << initRingNum << " " << t1 -t0 << endl; 
	}

	MPI_Finalize();

}
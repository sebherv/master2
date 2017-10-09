#include "common.h"
#include <iostream> // cout, cin
#include "mpi.h"

using namespace std;

int main(int argc, char *argv[]) {

	int nprocs, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	bool hasToContinue = true;

	// Wait for master to have retrieve the number of numbers to be sents
	MPI_Barrier(MPI_COMM_WORLD);

	int numReceived = 0;
	float totalSum = 0.0;

	while(hasToContinue) {
		float recvdFloat = 0;
		MPI_Status  status;
		// Send Request number
		MPI_Send(NULL, 0, MPI_FLOAT, RANK_MASTER, TAG_REQUEST_NUMBER, MPI_COMM_WORLD);

		MPI_Recv(&recvdFloat, 1, MPI_FLOAT, RANK_MASTER, TAG_SEND_NUMBER, MPI_COMM_WORLD, &status);
		if(recvdFloat >= 0) {
			cout << "Process " <<  rank << " received " << recvdFloat << " from master" << endl;
			numReceived++;
			totalSum += recvdFloat;
		} else {
			// Received negative number from master --> STOP
			hasToContinue = false;

		}

	}

	MPI_Barrier(MPI_COMM_WORLD);
	cout << "Process " << rank << " has finished; Received " << numReceived << " numbers, total value is " << totalSum << "." << endl;

	MPI_Finalize();

}
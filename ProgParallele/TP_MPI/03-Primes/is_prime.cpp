#include <iostream>
#include <cstring>
#include "mpi.h"

using namespace std;

const int MASTER_RANK = 0;

const int MODE_BLOCK = 100;
const int MODE_CYCLIC = 101;

int computeCyclicOne(int inputInt,int rank, int worldSize);
int computeBloc(int inputInt, int rank, int worldSize);

int main(int argc, char *argv[])
{

	int worldSize, rank;
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD,&worldSize);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int inputInt=0;
	int mode = 100;

	if(rank == MASTER_RANK) {

		for(int i=0; i < argc; i++) {
			if(strcmp("value", argv[i])==0) {
				sscanf(argv[i+1], "%d", &inputInt);
			}
			if(strcmp("mode_block", argv[i])==0) {
				mode = MODE_BLOCK;
			}
			if(strcmp("mode_cyclic", argv[i])==0) {
				mode = MODE_CYCLIC;
			}
		}

		if(inputInt == 0) {
			cout << "Veuillez saisir un nombre entier:" << endl;
			cin >> inputInt;
		}
	}

	// First broadcast the int
	MPI_Bcast(&inputInt, 1, MPI_INT, MASTER_RANK, MPI_COMM_WORLD);
	
	MPI_Barrier(MPI_COMM_WORLD);
	int foundPrimes = 0;
	double t0 = MPI_Wtime();
	if(mode == MODE_CYCLIC) {
		foundPrimes = computeCyclicOne(inputInt, rank, worldSize);
	} else {
		foundPrimes = computeBloc(inputInt, rank, worldSize);
	}

	int reducedResult;
	MPI_Reduce(&foundPrimes,&reducedResult,	1,MPI_INT,MPI_SUM,MASTER_RANK, MPI_COMM_WORLD);

	MPI_Barrier(MPI_COMM_WORLD);
	double t1 = MPI_Wtime();

	if(rank == MASTER_RANK) {	
		cout << "Found " << reducedResult << " prime numbers between 1 and " << inputInt << "; ";
		cout << t1-t0 << " wtime() elapsed " <<endl; 
	}

	MPI_Finalize();


}

int computeCyclicOne(int inputInt, int rank, int worldSize) {

	int foundPrimes = 0;
	// Cyclic pas == 1
	for(int current = 2 + rank; current < inputInt; current += worldSize ) {
		int i = 2;
		bool isPrime = true;
		while(i < current && isPrime) {
			if(current % i == 0) {
				isPrime = false;
			}
			i++;
		}
		if(isPrime) {
			foundPrimes++;
		}
	}
	return foundPrimes;

}

int computeBloc(int inputInt, int rank, int worldSize) {

	int foundPrimes = 0;

	int blocSize = (inputInt - 2) / worldSize; // Keep in mind we don't count 0 and 1.
	int remainder =(inputInt - 2) % worldSize;
	int blockWithRemainderSize = blocSize + 1;

	// Compute indexes for block start and block end
	int blockStart = 0;
	int blockEnd = 0;
	for(int i = 0 ; i < rank; i++) {
		// First spread the remainder to the first n ranks
		// end shit the block start and end indexes accordingly
		if(i < remainder) {
			blockStart += blockWithRemainderSize;
		} else {
			blockStart += blocSize;
		}
	}

	blockEnd += (rank < remainder) ? blockWithRemainderSize : blocSize;
	
	for(int current = blockStart;
		current < blockEnd;
		current++ ) {
		current += 2; // Keep in mind we don't count 0 and 1.
		int i = 2;
		bool isPrime = true;
		while(i < current && isPrime) {
			if(current % i == 0) {
				isPrime = false;
			}
			i++;
		}
		if(isPrime) {
			foundPrimes++;
		}
	}
	return foundPrimes;

}


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

	int blocSize = (inputInt - 2) / worldSize;
	int remainder =(inputInt - 2) % worldSize;

	
	for(int current = 2 + (rank * blocSize);
		current < 2 + blocSize * (rank + 1) + (rank + 1 > remainder) ? 0 : 1 ;
		current++ ) {
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


#include <iostream>
#include "mpi.h"

const int MASTER_RANK = 0;


using namespace std;

int computeCyclicOne(int inputInt,int rank, int worldSize);

int main(int argc, char *argv[])
{

	int worldSize, rank;
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD,&worldSize);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int inputInt;

	if(rank == MASTER_RANK) {
		cout << "Veuillez saisir un nombre entier:" << endl;
		cin >> inputInt;
	}

	// First broadcast the int
	MPI_Bcast(&inputInt, 1, MPI_INT, MASTER_RANK, MPI_COMM_WORLD);
	
	MPI_Barrier(MPI_COMM_WORLD);
	double t0 = MPI_Wtime();
	int foundPrimes = computeCyclicOne(inputInt, rank, worldSize);

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

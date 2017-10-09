#include <iostream>
#include "mpi.h"

const int MASTER_RANK = 0;


using namespace std;

int main()
{

	int nprocs, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == MASTER_RANK) {
		cout << "Veuillez saisir un nombre entier:" << endl;
		int monInt;
		cin >> monInt;
	}


	// Generator array of all the int to be checked for being primes
	int* intArray = new int[monInt - 1];
	for(int i = 0; i < monInt - 1; i++) {
		intArray[i] = i + 2;
	}

	MPI_Scatter(intArray, monInt - 1, MPI_INT, intArray, 100, MPI_INT,root, MPI_COMM_WORLD);
	//double t0 = omp_get_wtime(); 
	int foundPrimes = 0;
		for(int current = 2; current < monInt; current++) {
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

	MPI_Reduce(&sendbuf,&recvbuf,len,type,op,root, comm);

	//double t1 = omp_get_wtime();
	cout << "Found " << foundPrimes << " prime numbers between 1 and " << monInt << "; ";
	cout << t1-t0 << " wtime() elapsed " <<endl; 


}

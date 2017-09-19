#include <iostream>

#ifdef _OPENMP
#include "omp.h"
#endif

static int MAXSIZE = 100;

using namespace std;

int main()
{
	//Init un tableau d'entier size = 100
	int mesEntiers[MAXSIZE];
	int i;
	
	// Run in parallel
	#ifdef _OPENMP
	#pragma omp parallel for schedule(guided,5)
	for(i = 0; i < MAXSIZE; i++)
	{
		mesEntiers[i] = omp_get_thread_num();
	}
	#endif
	
	// After parallel run dump the array
	// and calculate number of chunks
	int maxThread = omp_get_max_threads();
	int iterationPerThread[maxThread];
	for (i = 0; i < maxThread ; i++) {
		iterationPerThread[i] = 0;
	}
	
	for( i = 0; i < MAXSIZE; i++)
	{
		cout << "mesEntiers[" << i << "] = " << mesEntiers[i] << endl;
		iterationPerThread[mesEntiers[i]]++;
	}
	
	// Finaly print the number of iteration per thread
	for (i = 0; i < maxThread ; i++) {
		cout << "Thread " << i << " has processed " << iterationPerThread[i] << " iterations." << endl;
	}
}

#include <iostream>

#ifdef _OPENMP
#include "omp.h"
#endif

using namespace std;

int main()
{
	int numthreads, rank;
#ifdef _OPENMP
#pragma omp parallel private(rank)
{
	// Hello world
	numthreads = omp_get_num_threads();
	rank = omp_get_thread_num();
	#pragma omp critical
	{
		cout << "Hello world from thread " << rank << " out of " << numthreads << "." << endl;
	}
}
#endif
}

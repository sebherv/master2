#include <iostream>

#ifdef _OPENMP
#include "omp.h"
#endif

using namespace std;

int main()
{
	int numthreads, rank;
	int numThreadsToSet;
	
	cout << "Please enter a number of threads:" << endl;
	cin >> numThreadsToSet;
	
	omp_set_num_threads(numThreadsToSet);
	
#ifdef _OPENMP
#pragma omp parallel private(rank, numthreads)
	{
		// Hello world
		numthreads = omp_get_num_threads();
		rank = omp_get_thread_num();
		int maxthreads = omp_get_max_threads();
		#pragma omp critical
		{
			cout << "Hello world from thread " << rank << " out of " << numthreads << ", ";
			cout << "omp_get_max_thread()=" << maxthreads << endl;
		}
	}
#endif
	cout << "After parallel section; omp_get_max_thread()=" << omp_get_max_threads() << endl;
}

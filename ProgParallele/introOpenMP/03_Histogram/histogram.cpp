#include <iostream>
#include <cmath>
#include <stdlib.h>

#ifdef _OPENMP
#include "omp.h"
#endif

using namespace std;

int main() {
	int side = 10000;
	const int slotsNbr = 10;
	// Init array size is n * n
	srand(time(NULL));
	int totalSize = side * side;

	float* floatArray = new float[totalSize];

	// Fill in array
	for(int i = 0; i < totalSize; i++) {
		floatArray[i] = rand() % 10;
	}

	// Init int array to hold histogram
	int histogram[slotsNbr];
	for(int i = 0; i < slotsNbr; i++) {
		histogram[i] = 0;
	}

	#ifdef _OPENMP
	double t0 = omp_get_wtime();
    #pragma omp parallel shared(histogram)
    {
		// Init a private Histogram for each
		int privateHisto[slotsNbr] = {0};
		
		// Scan the array for values
		#pragma omp for schedule(static)
		for(int i = 0; i < totalSize; i++) {
			int index = floor(floatArray[i]);
			privateHisto[index]++;
		}
		
		#pragma omp critical
		{
			cout << "This is thread " << omp_get_thread_num() << " saving histo" << endl;
			for(int i = 0; i < slotsNbr; i++) {
				histogram[i] = privateHisto[i];
			}
		}
	}
	double t1 = omp_get_wtime();
	#endif
	

	// Once finished display result
	int total = 0;
	for(int i = 0; i < slotsNbr; i++) {
		cout << histogram[i] << " between " << i << " and " << i+1 << endl;
		total += histogram[i];
	}

	cout << "total counted is : " << total << endl;
	cout << "theoric total is : " << totalSize << endl;
	cout << "Elapsed wall clock time: " << t1-t0 << endl;
	
	delete [] floatArray;
 

}

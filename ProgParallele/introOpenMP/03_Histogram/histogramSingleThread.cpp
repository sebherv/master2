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

	float* floatArray = (float*)malloc(sizeof(float) * totalSize);

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
	// Scan the array for values
	for(int i = 0; i < totalSize; i++) {
		int index = floor(floatArray[i]);
		histogram[index]++;
	}
	double t1 = omp_get_wtime();
	#endif

	// Once finished display result
	int total = 0;
	for(int i = 0; i < slotsNbr; i++) {
		cout << histogram[i] << " between " << i << " and " << i+1 << endl;
	}

	cout << "total counted is : " << total << endl;
	cout << "theoric total is : " << totalSize << endl;
	cout << "Elapsed wall clock time";
 

}
#include "transposeSort.h"
#include <iostream>
#include <stdlib.h>

#ifdef _OPENMP
#include "omp.h"
#endif



using namespace std;


int main() {
	// Nombre d'entrée à trier
	int iterAtEachSize = 10;
	int arraySize = 0;
	int faultyIndex = 0;
	srand(time(NULL));
	
	for( int threadnum = 1; threadnum <= 4; threadnum++) {
		for(arraySize = 100; arraySize < 50000;  (arraySize > 1000) ? arraySize *=2: arraySize*=10) {
			for(int iter = 0; iter < iterAtEachSize; iter++) {
				omp_set_num_threads(threadnum);
				float * valueArray = initArray(arraySize);
		
				cout << threadnum << "; " << arraySize << "; ";
		
				double t0 = omp_get_wtime(); 		
				sortArray(valueArray, arraySize);
				double t1 = omp_get_wtime();
		
				cout <<  t1 - t0 << ";  ";
				if(checkArraySorted(valueArray, arraySize, faultyIndex)) {
					cout << "Sorting Ok" << endl;
				} else {
					cout << "Array was NOT correctly sorted!! ";
					cout << "Error at index " << faultyIndex << endl;
				}
				delete[] valueArray;
			} // for iter
		} // for array size
	} // forthread num
}

float* initArray(int arraySize) {
	float * valueArray = new float[arraySize];

	for(int i = 0; i < arraySize; i++) {
		valueArray[i] = rand();
	}

	return valueArray;
}

void sortArray(float * arrayToBeSorted, int arraySize) {
	int initialIndex = 0; // corresponds to the uneven phase
		
	for(int phase = 0; phase < arraySize ; phase++) {
		// Normalement par design, 
		#pragma omp parallel for schedule(static,5) 
		for(int i = 0; i < arraySize/2; i++) {
			int index = i*2 + initialIndex;
			if((arrayToBeSorted[index] > arrayToBeSorted[index+1])&&( index+1 < arraySize)) {
				float temp = arrayToBeSorted[index];
				arrayToBeSorted[index] = arrayToBeSorted[index+1];
				arrayToBeSorted[index+1] = temp;
			}
		} // #pragma omp

		if(initialIndex == 0) {
			initialIndex = 1;  // Even phase
		} else {
			initialIndex = 0; // Uneven phase
		}
	}
}


bool checkArraySorted(float * sortedArray, int arraySize, int &faultyIndex ) {
	int i = 0;
	while( i < arraySize - 1) {
		if(sortedArray[i] > sortedArray[i+1]) {
			faultyIndex = i;
			return false;
		}
		i++;
	}

	return true;
}





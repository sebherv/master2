#include "transposeSort.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


int main() {
	// Nombre d'entrée à trier
	int arraySize = 100000;

	float * valueArray = initArray(arraySize);
	sortArray(valueArray, arraySize);
	if(checkArraySorted(valueArray, arraySize)) {
		cout << "Array was correctly sorted" << endl;
	} else {
		cout << "Array was NOT correctly sorted" << endl;
	}

	free(valueArray);
}

float* initArray(int arraySize) {
	float * valueArray = (float*) malloc(sizeof(float) * arraySize);
	srand(time(NULL));
	for(int i = 0; i < arraySize; i++) {
		valueArray[i] = rand();
	}

	return valueArray;
}

void sortArray(float * arrayToBeSorted, int arraySize) {
	int initialIndex = 0; // corresponds to the uneven phase
	for(int phase = 0; phase < arraySize; phase ++) {
		for(int i = initialIndex; i < arraySize; i = i + 2) {
			if(i + 1 < arraySize) { // make sure the last index does not overrun in the even phase
				if(arrayToBeSorted[i] > arrayToBeSorted[i+1]) {
					// switch the 2
					float temp = arrayToBeSorted[i];
					arrayToBeSorted[i] = arrayToBeSorted[i+1];
					arrayToBeSorted[i+1] = temp;
				}
			}
		}
		if(initialIndex == 0) {
			initialIndex = 1;  // Even phase
		} else {
			initialIndex = 0; // Uneven phase
		}
	}
}


bool checkArraySorted(float * sortedArray, int arraySize ) {
	int i = 0;
	while( i < arraySize - 1) {
		if(sortedArray[i] > sortedArray[i+1]) {
			return false;
		}
		i++;
	}

	return true;
}





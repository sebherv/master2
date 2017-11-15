#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>


MATRIX * allocMatrix(int width, int height) {
	MATRIX* newMatrixPtr = malloc(sizeof(MATRIX));
	if(newMatrixPtr == NULL) {
		printf("Unable to allocate new matrix.\n");
		exit(-1);
	}

	newMatrixPtr->width = width;
	newMatrixPtr->height = height;
	newMatrixPtr->elemNbr = width * height;
	newMatrixPtr->elements = (double*)malloc(newMatrixPtr->elemNbr * sizeof(double));
	newMatrixPtr->val = (double**)malloc(height*sizeof(double*));

	int i;
	for(i = 0; i < newMatrixPtr->height; i++) {
		newMatrixPtr->val[i] = (newMatrixPtr->elements + width * i);
	}

	return newMatrixPtr;
}

void freeMatrix(MATRIX* matrixPtr) {
	free(matrixPtr->val);
	free(matrixPtr->elements);
	free(matrixPtr);
}


double getCij(MATRIX* matrix,int i, int j) {
	// Check index validity
	if(i < 0 || i > matrix->width) {
		printf("MATRIX::getCij(): index i out of bound: %d\n", i);
	}
	if(j < 0 || j > matrix->height) {
		printf("MATRIX::getCij(): index j out of bound: %d\n", j);
	}

	return matrix->val[i][j];

}



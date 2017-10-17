#include <stdlib.h>
#include "point.h"

POINTS_ARRAY* allocPoints(int dim, int size) {
	POINTS_ARRAY* pointsArray = (POINTS_ARRAY*)malloc(sizeof(POINTS_ARRAY));
	double * pointsPtr = (double*)calloc(sizeof(double)*dim*size,0);
	pointsArray->dim = dim;
	pointsArray->size = size;
	pointsArray->buffer = pointsPtr;
	int i;
	for(i=0; i<size; i++) {
		pointsArray->val[i] = &pointsPtr[i*dim*sizeof(double)];
	}
	return pointsArray;
}

void freePoints(POINTS_ARRAY * pointsArray) {
	free(pointsArray->val);
	free(pointsArray->buffer);
	free(pointsArray);
}


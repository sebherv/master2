#include <stdlib.h>
#include "point.h"

POINTS_ARRAY* allocPoints(int dim, int size) {
	POINTS_ARRAY* pointsArray = (POINTS_ARRAY*)malloc(sizeof(POINTS_ARRAY));
	double * pointsPtr = (double*)calloc(sizeof(double)*dim*size,0);
	pointsArray->dim = dim;
	pointsArray->size = size;
	pointsArray->val = pointsPtr;

	return pointsArray;
}

void freePoints(POINTS_ARRAY * pointsArray) {
	free(pointsArray->val);
	free(pointsArray);
}


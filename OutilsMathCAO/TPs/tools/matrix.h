#ifndef MATRIX_H
#define MATRIX_H


typedef struct MATRIX {
	int width;
	int height;
	int elemNbr;
	double ** val;
	double * elements;
} MATRIX;

/* Allocates a matrix of the given width and height */
MATRIX * allocMatrix(int width, int heigth);

/* Atomatically frees the passed in matrix */
void freeMatrix(MATRIX* matrixPtr);

/* --- Element access --- */

/* Get element at ij */
double getCij(MATRIX* matrix,int i, int j);

#endif


#include "matrix.h"
#include "fileUtils.h"
#include "../tp6-CarreauBezier/controlNetwork.h"
#include <stdio.h>
#include <stdlib.h>


MATRIX * importControlNetwork(char* filename) {

	FILE * fptr;
	char* line = NULL;
	size_t read;
	size_t len;

	int m = 0;
	int n = 0;
	int dim = 0;

 fptr = fopen(filename, "r");
	if (fptr == NULL) {
		printf("Error could not open data file %s\n", filename);
		exit(1);
	}

	// Read first line
	if((read = getline(&line, &len, fptr )) != -1) {
		double mf = 0.0;
		double nf = 0.0;
		double dimf = 0.0;
		sscanf(line, "%lf %lf %lf", &mf, &nf, &dimf);
		m = (int)mf;
		n = (int)nf;
		dim = (int)dimf;
		printf("Retrieving file for matrix %d x %d in dim %d\n", m, n, dim);
	} else {
		printf("Could not read first line from %s\n", filename);
		exit(1);
	}

	CONTROL_NETWORK

	return NULL;
}

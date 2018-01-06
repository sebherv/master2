#include "controlNetwork.h"
#include <stdlib.h>

CONTROL_NETWORK * allocControlNetwork(int nbrOfLines, int nbrOfRows, int dim) {
	CONTROL_NETWORK * cn = malloc(sizeof(CONTROL_NETWORK));
	cn->matrix = allocMatrix(dim, nbrOfLines * nbrOfRows);
	cn->nbrOfLines = nbrOfLines;
	cn->nbrOfRows = nbrOfRows;
    return cn;
}


void freeControlNetwork(CONTROL_NETWORK * cn) {
	freeMatrix(cn->matrix);
	free(cn);
}



#include "../tools/matrix.h"

typedef struct CONTROL_NETWORK {
	int nbrOfLines;
	int nbrOfRows;
	MATRIX * matrix;
} CONTROL_NETWORK;

CONTROL_NETWORK * allocControlNetwork(int nbrOfLines, int nbrOfRows, int dim);
void freeControlNetwork(CONTROL_NETWORK * controlNetwork);
#include "../tools/matrix.h"

typedef struct CONTROL_NETWORK {
	int nbrOfLines;
	int nbrOfRows;
	MATRIX * matrix;
} CONTROL_NETWORK;

CONTROL_NETWORK * allocateControlNetwork(int nbrOfLines, int nbrOfRows);
void freeControlNetwork(CONTROL_NETWORK * controlNetwork);
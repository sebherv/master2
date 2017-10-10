

typedef struct POINT {
  double x;
  double y;
} POINT;

#define DATA_FILE "contpoints.dat"
#define OUTPUT_FILE "bezier_result.dat"

POINT* importDataFile(int * numberOfControlPoints);

void saveOutputPoints(POINT* pointsToSave, int numberOfPoints);

POINT* generateBezierSubdivision(POINT* controlBox, 
                                    int n,
                                    int j,
                                    int * numberOfGenPoints);


double deCasteljauONE(double x, double iCurrent, double iPlusOne);
void DC(int n, int dim, POINT* buffer);

double* splitLineToFloats(char * line, int * nbrOfPts);
void performSubdivision(POINT * workBuffer, int n, int j, int jmax, int sourceSlot, int outputSlot);

void elementarySubdivision(POINT * pointsBuffer, POINT * gdBuffer, int n ); 
int getElementaryBufferSize(int n);


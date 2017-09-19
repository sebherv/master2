

typedef struct POINT {
  double x;
  double y;
} POINT;

#define DATA_FILE "contpoints.dat"
#define OUTPUT_FILE "bezier_result.dat"

POINT* importDataFile();

void saveOutputPoints(POINT* pointsToSave, int numberOfPoints);

POINT* generateBezierFromControlBox(POINT* controlBox, 
                                    int numberOfControlPoints, 
                                    int numberOfCurvePoints);

double deCasteljauONE(double x, double iCurrent, double iPlusOne);
void DC(POINT* controlPts, int n, int dim, double currentX, POINT * resultPoint, POINT* buffer);
int getBufferIndex(int n, int i, int k);
int getBufferSize(int n);
double* splitLineToFloats(char * line, int * nbrOfPts);


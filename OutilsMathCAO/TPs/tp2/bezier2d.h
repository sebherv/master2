

typedef struct POINT {
  double x;
  double y;
} POINT;

#define DATA_FILE "contpoints.dat"
#define OUTPUT_FILE "bezier_result.dat"

POINT* importDataFile(int * numberOfControlPoints);

void saveOutputPoints(POINT* pointsToSave, int numberOfPoints);

POINT* generateBezierSubdivision(POINT* controlBox, 
                                    int numberOfControlPoints, 
                                    int numberOfCurvePoints);

double deCasteljauONE(double x, double iCurrent, double iPlusOne);
void DC(POINT* controlPts, int n, int dim, double currentX, POINT * resultPoint, POINT* buffer);

int getEvalBufferIndex(int n, int i, int k);
int getEvalBufferSize(int n);
int getSubdivBufferSize(int n, int j);
int getSubdivBufferIndex(int n, int j);

double* splitLineToFloats(char * line, int * nbrOfPts);


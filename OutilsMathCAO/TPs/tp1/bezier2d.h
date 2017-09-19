

typedef struct POINT {
  double x;
  double y;
} POINT;

#define DATA_FILE "contpoints.dat"

POINT* importDataFile();

POINT* generateBezierFromControlBox(POINT* controlBox, 
                                    int numberOfControlPoints, 
                                    int numberOfCurvePoints);

POINT* iterateDeCasteljau(POINT* kMinusOne, int numberOfInputPoints, double currentX);

double* splitLineToFloats(char * line, int * nbrOfPts);


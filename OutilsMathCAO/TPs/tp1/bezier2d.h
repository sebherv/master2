

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

POINT* iterateDeCasteljau(POINT* kMinusOne, int numberOfInputPoints, double currentX);
double deCasteljauONE(double x, double iCurrent, double iPlusOne);
double* splitLineToFloats(char * line, int * nbrOfPts);


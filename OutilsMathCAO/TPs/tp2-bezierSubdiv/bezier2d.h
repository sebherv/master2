

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
                                    int j);

void performSubdivision(POINT * workBuffer, int n, int position, int j, int jmax);

double deCasteljauONE(double x, double iCurrent, double iPlusOne);
void DC(int n, int dim, POINT* buffer);

int getEvalBufferIndex(int n, int i, int k);
int getEvalBufferSize(int n);
int getSubdivBufferSize(int n, int j);
int getSubdivBufferIndex(int n, int j);
void copyDeltas(POINT* workBuffer, int evalPosition, int rightPosition, int n);
void copyGammas(POINT* workBuffer, int evalPosition, int leftPosition, int n);

double* splitLineToFloats(char * line, int * nbrOfPts);


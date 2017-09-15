

typedef struct POINTS {
  double x;
  double y;
} POINTS;

#define DATA_FILE "contpoints.dat"

POINTS* importDataFile();

double* splitLineToFloats(char * line, int * nbrOfPts);


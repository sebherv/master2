#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bezier2d.h"


static int numberOfOutputPoints = 100;
static int iterMax = 2;

int main()
{ 

  POINT* controlPoints;
  int numberOfControlPoints;

  // import data
  controlPoints = importDataFile(&numberOfControlPoints);

  // Generate curve data
  POINT* curveData;
  curveData = generateBezierSubdivision(controlPoints, numberOfControlPoints, iterMax);

  // Print out data
  int i;
  for(i=0; i<numberOfOutputPoints; i++)
  {
    printf("point %d, x=%lf, y=%lf\n", i, curveData[i].x, curveData[i].y);
  } 
  
  // Save points
  saveOutputPoints(curveData, numberOfOutputPoints);


  // Free memory
  free(controlPoints);


}

POINT* generateBezierSubdivision(POINT* controlBox, 
                                    int n, 
                                    int maxIter)
{

  // Will hold the result points
  POINT* curvePoints = (POINT *)malloc(sizeof(POINT) * getEvalBufferSize());
  
  // Will hold all the subdivision algorithms
  POINT* workBuffer = (POINT *)malloc(sizeof(POINT) * getSubdivBufferSize(n, maxIter) );
  
  // Copy control points in work buffer
  int i;
  for(i = 0; i < n; i++) {
	  workBuffer[i].x = controlBox[i].x;
	  workBuffer[i].y = controlBox[i].y;
  }

  performSubdivision()

  return NULL;
  
}

void performSubdivision(POINT * workBuffer, int n, int position, int j, int jmax) {

	// Recursive call perform the subdivision algorithm
  DC( n, 2, workBuffer);
  
  int rightPosition = position * 2;
  int leftPosition = rightPosition - 1;

  copyDeltas(workBuffer, position, rightPosition);
  performSubdivision(workBuffer, n, rightPosition, int j+1, int jmax);

  copyGammas(workBuffer, position, leftPosition);
  performSubdivision(workBuffer, n, leftPosition, int j+1, int jmax);

  return;
	
}


/*
 * Performs an interation of the DC1 algorithms
 * one a single coordinate
 */
double deCasteljauONE(double x, double iCurrent, double iPlusOne)
{
	return (1 - x) * iCurrent + x * iPlusOne; 
}


void DC(int n, int dim, POINT* buffer)
{
	/*
	 * Algorithme de De Casteljau DC Evaluation
	 * Arguments
	 * - n: le nombre de points de contrôle
	 * - dim: la dimension de travail
	 * - resultPoint: un pointeur vers une struct POINT pour stocker le résultat
	 * - buffer: le buffer de travail, qui doit être de taille suffisante pour permettre à l'algorithme de fonctionner correctement
	 *   Les n premiers points sont les points de controle de départ.
	 */

  // Iterate DC
  int k, i;
  for(k = 1; k < n; k++)
  {
    for(i = 0; i < n-k; i++)
    {
      buffer[getEvalBufferIndex(n, i, k)].x = deCasteljauONE(0.5,
                                                buffer[getEvalBufferIndex(n,  i,  k-1)].x,
                                                buffer[getEvalBufferIndex(n,  i+1,k-1)].x);
      buffer[getEvalBufferIndex(n, i, k)].y = deCasteljauONE(0.5,
                                                buffer[getEvalBufferIndex(n,  i,  k-1)].y,
                                                buffer[getEvalBufferIndex(n,  i+1,k-1)].y);

    }
  }

}

int getEvalBufferIndex(int n, int i, int k)
{
	/*
	 * Retourne l'index de buffer à utiliser pour accéder à la 
	 * donnée P_k(i)
	 */
	 int base = n*(n+1)/2;
   base -= (n-k)*(n-k+1)/2;
   return base + i;
}

int getEvalBufferSize(int n)
{
  return n * (n+1) / 2;
}

int getSubdivBufferSize(int n, int j) {
  /*
  * Returns the buffer size required to implement
  * the subdivision algorithm, with the following 
  * arguments:
  *  - n: the number of control points
  *  - j: the number of iterations to perform.
  */
  int evalBufferSize = getEvalBufferSize(n);
  return 2^j * evalBufferSize; 
}

int getSubdivBufferIndex(int n, int iter) {
  /*
  * Returns the index of the evaluation algo first element 
  * in the subdivision work array
  * - n: number of control points
  * - iter: number of the iteration
  */
  int evalBufferSize = getEvalBufferSize(n);
  return iter * evalBufferSize;
}

void copyGammas(int n, int evalBufferIndex, int subdivBufferIndex, POINT* buffer) {
  /*
  * copies the gammas to the subdivision 
  * buffer, with following arguments
  * - n: number of control points
  * - evalBufferIndex: start index of the eval work buffer to extract the gammas from
  * - subdivBufferIndex: start index of the subdiv buffer the gammas are to be copied to
  */
  int evalBufferSize = getEvalBufferSize(n);

}

int getGammaIndex(int n, int col) {
  /*
  * Returns the index of the col-th gamma index
  */
  return getEvalBufferIndex(n, 0, col);

}

void copyDeltas() {

}

int getDeltaIndex(int n, int col) {
	return getEvalBufferIndex(n, n-col, col );
}


POINT* importDataFile(int * numberOfControlPoints)
{

  //open file and read line by line
  FILE *fptr;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  double * readValues;
  int numberOfPoints;
  int dim;

  POINT * toReturn = NULL;
  POINT * current;

  fptr = fopen(DATA_FILE, "r");
 
  if(fptr == NULL)
  {
     printf("Error! Could not open data file\n");   
     exit(1);             
  }

  int numberOfLines = 0;

  // First count the number of lines;
  while((read = getline(&line, &len, fptr)) != -1) {
    numberOfLines++;
  }

  rewind(fptr);
  numberOfPoints = numberOfLines;

  // Read the first line to see dim of the points
  while ((read = getline(&line, &len, fptr)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
        readValues = splitLineToFloats(line, &dim);
        if(toReturn == NULL) {
            // Init toReturn:
            current = toReturn = (POINT *)malloc(sizeof(POINT) * numberOfLines);

        }
        current->x= readValues[0];
        current->y= readValues[1];
        current++;

  }

  // Close file
  printf("Closing file\n");
  fclose(fptr);

  printf("Building Control Points array\n");


  *numberOfControlPoints = numberOfPoints;

  return toReturn;
  
}

// Returned double* must be freed after use
double* splitLineToFloats(char * line, int * nbrOfPts) {

  char *token, *str, *tofree;
  int count;

  tofree = str = strdup(line);
  
  // Count number of occurence of séparator
  for (count=0; line[count]; line[count]==',' ? count++ : *line++);
  count++;

  *nbrOfPts = count;
    
  // Allocate buffer for double array
  double * toReturn = (double *)malloc(sizeof(double)* (count));

  // Split lines and get double values
  int index = 0;
  while ((token = strsep(&str, ","))) {
    if(!sscanf(token, "%lf", &toReturn[index]))
    {
      printf("Problem while converting string to float");
      exit(0);
    }
    index++;
  }
  
  free(tofree);

  return toReturn;
}

// Saves the Points in file
void saveOutputPoints(POINT* pointsToSave, int numberOfPoints)
{
	FILE *fp;

   fp = fopen(OUTPUT_FILE, "w+");
   int i;
   for(i = 0; i < numberOfPoints; i++) {
	   fprintf(fp, "%lf %lf\n", pointsToSave[i].x, pointsToSave[i].y);
   }
   fclose(fp);
}



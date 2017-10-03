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
  printf("About to call generateBezierSubdivision()\n");
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
  POINT* curvePoints = (POINT *)malloc(sizeof(POINT) * (2*n +1));
  
  printf("Copying control points into workBuffer\n");
  
  // Copy control points in work buffer
  int i;
  for(i = 0; i < n; i++) {
	  curvePoints[n+i].x = controlBox[i].x;
	  curvePoints[n+i].y = controlBox[i].y;
  }

  performSubdivision(workBuffer, n, 0, maxIter);

  return workBuffer;
  
}

void performSubdivision(POINT * workBuffer, int n, int j, int jmax) {
  printf("performSubdivision() level %d\n", j);

	
  
  int rightPosition = position * 2;
  int leftPosition = rightPosition - 1;

  if(j < jmax) {
    performSubdivision(workBuffer, n, rightPosition, j+1,  jmax);
    performSubdivision(workBuffer, n, leftPosition, j+1,  jmax);
  }

  printf("Returning from performSubdivision level %d\n",j);
  return;
	
}

void elementarySubdivision(POINT * pointsBuffer, POINT * gBuffer, int n ) {

  int k = 0;
  int i = 0;

  // Save the gammas
  gdBuffer[k].x = pointsBuffer[0].x;
  gdBuffer[k].y = pointsBuffer[0].y;

  for(i = O; i < (n-k); i++) {
    pointsBuffer[i].x = deCasteljauONE(0.5, pointsBuffer[i].x, pointsBuffer[i].x);
    pointsBuffer[i].y = deCasteljauONE(0.5, pointsBuffer[i].y, pointsBuffer[i].y);
  }
}


/*
 * Performs an interation of the DC1 algorithms
 * one a single coordinate
 */
double deCasteljauONE(double x, double iCurrent, double iPlusOne)
{
	return (1 - x) * iCurrent + x * iPlusOne; 
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
        //printf("Retrieved line of length %zu :\n", read);
        //printf("%s", line);
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
  //printf("Closing file\n");
  fclose(fptr);

  printf("Building Control Points array with %d points\n", numberOfPoints);


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



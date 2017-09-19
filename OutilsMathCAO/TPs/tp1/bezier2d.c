#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bezier2d.h"


static int numberOfOutputPoints = 16;

int main()
{ 

  POINT* controlPoints;
  int numberOfControlPoints;

  // import data
  controlPoints = importDataFile(&numberOfControlPoints);

  // Generate curve data
  POINT* curveData;
  curveData = generateBezierFromControlBox(controlPoints, numberOfControlPoints, numberOfOutputPoints);


  // Print out data
  int i;
  for(i=0; i<numberOfOutputPoints; i++)
  {
    printf("point %d, x=%lf, y=%lf\n", i, curveData[i].x, curveData[i].y);
  } 


  // Free memory
  free(controlPoints);


}

POINT* generateBezierFromControlBox(POINT* controlBox, 
                                    int numberOfControlPoints, 
                                    int numberOfCurvePoints)
{
  // Generate for n points
  int n;
  double step = 1 / numberOfCurvePoints;
  double currentX;

  POINT* curvePoints = malloc(sizeof(POINT) * numberOfCurvePoints);

  for(n=0; n < numberOfCurvePoints; n++) {
    currentX = n * step;
    POINT * currentPoint;
    currentPoint = iterateDeCasteljau(controlBox, numberOfControlPoints, currentX);
    curvePoints[n].x = currentPoint->x;
    curvePoints[n].y = currentPoint->y;

    free(currentPoint); 

  }

  return curvePoints;
  

}

POINT* iterateDeCasteljau(POINT* kMinusOne, int numberOfInputPoints, double currentX)
{
  int numberOfPointAtEndOfIteration = numberOfInputPoints -1;
  POINT * outputPoints = malloc(sizeof(POINT) * numberOfPointAtEndOfIteration);

  int i;
  for(i = 0; i < numberOfPointAtEndOfIteration; i++)
  {
    outputPoints[i].x = (1-currentX)*kMinusOne[i].x + currentX * kMinusOne[i+1].x;
    outputPoints[i].y = (1-currentX)*kMinusOne[i].y + currentX * kMinusOne[i+1].y;  
  }

  //free(kMinusOne);

  if(numberOfPointAtEndOfIteration == 1)
  {
    return outputPoints;
  }
  else
  {
    return iterateDeCasteljau(outputPoints, numberOfPointAtEndOfIteration, currentX);
  }

}




POINT* importDataFile(int * numberOfControlPoints)
{

  //open file and read line by line
  FILE *fptr;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  double * xvalues;
  double * yvalues;
  int numberOfPoints;

  fptr = fopen(DATA_FILE, "r");
 
  if(fptr == NULL)
  {
     printf("Error! Could not open data file\n");   
     exit(1);             
  }

  // Read 2 first lines and ignore rest
  if ((read = getline(&line, &len, fptr)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
        xvalues = splitLineToFloats(line, &numberOfPoints);
  }

  if ((read = getline(&line, &len, fptr)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
        yvalues = splitLineToFloats(line, &numberOfPoints);
        
  }

  // Close file
  printf("Closing file\n");
  fclose(fptr);

  printf("Building Control Points array\n");

  POINT* toReturn = malloc(sizeof(POINT) * numberOfPoints);

  int index;
  for(index = 0; index < numberOfPoints; index++)
  {
    toReturn[index].x = xvalues[index];
    toReturn[index].y = yvalues[index];
  }

  *numberOfControlPoints = numberOfPoints;

  free(xvalues);
  free(yvalues);

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
  double * toReturn = malloc(sizeof(double)* (count));

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


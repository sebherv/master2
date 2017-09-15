#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bezier2d.h"


POINTS* importDataFile()
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

  printf("Building Controle Points array\n");

  return NULL;
  
}

// Returned double* must be freed after use
double* splitLineToFloats(char * line, int * nbrOfPts) {

  char *token, *str, *tofree;
  int count;
  
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

int main()
{
  importDataFile();


}

#include <stdlib.h>
#include <stdio.h>



typedef struct POINTS {
  double x;
  double y;
} POINTS;

#define DATA_FILE "contpoints.dat"

void importDataFile()
{

  //open file and read line by line
  FILE *fptr;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  fptr = fopen(DATA_FILE, "r");
 
  if(fptr == NULL)
  {
     printf("Error! Could not open DATA_FILE");   
     exit(1);             
  }

  // Read Lines
  while ((read = getline(&line, &len, fptr)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
  }



  // Close file
  fclose(fptr);

  
}

int main()
{



}

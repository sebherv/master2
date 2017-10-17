


typedef struct POINT {
	double * val;
}


// Structure pour encapsuler une liste de points de dimension dim
// Tous les points auront une dimension dim
typedef struct POINTS_ARRAY {
	int dim;
	int size; 
	double * val  // TODO ACCESS AS TABLE ??
} POINTS_ARRAY;

POINTS_ARRAY * allocPoints(int dim, int size);
void freePoints(POINTS_ARRAY * pointsArray);



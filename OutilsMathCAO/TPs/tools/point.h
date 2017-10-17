


// Structure pour encapsuler une liste de points de dimension dim
// Tous les points auront une dimension dim
typedef struct POINTS_ARRAY {
	int dim;
	int size; 
	double ** val;
	double * buffer;
} POINTS_ARRAY;

POINTS_ARRAY * allocPoints(int dim, int size);
void freePoints(POINTS_ARRAY * pointsArray);



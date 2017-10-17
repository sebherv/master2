

// Structure pour stocker un point de dimension arbitraire
typedef struct POINT {
	double * values;
} POINT;


// Structure pour encapsuler une liste de points de dimension dim
// Tous les points auront une dimension dim
typedef struct POINTS {
	int dim;
	int size;
	POINT * 
}

POINTS * allocPoints(int dim, int size);
void freePoints(POINTS * points);



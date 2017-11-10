#ifndef MATRICE1_H
#define MATRICE1_H

class Matrice {
	int nbl, nbc;
	double **val;
public:
	Matrice (int nl=0, int nc=0);
	void affiche (const char *);
	Matrice operator*(Matrice& B);
};
#endif

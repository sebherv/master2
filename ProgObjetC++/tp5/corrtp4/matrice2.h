#ifndef MATRICE2_H
#define MATRICE2_H

class Matrice {
	int nbl, nbc;
	double **val;
public:
	Matrice (int nl=0, int nc=0);
	~Matrice ();
	void init (const double r);
	void affiche (const char *);
	Matrice operator*(Matrice& B);
};
#endif

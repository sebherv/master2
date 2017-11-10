#ifndef MATRICE3_H
#define MATRICE3_H

#include <iostream>

class Matrice {
	int nbl, nbc;
	double **val;
	void allocval (double **&val, int nl, int nc);
	void freeval (double **&val, int nl);
public:
	Matrice (int nl=0, int nc=0);
	Matrice (const Matrice& Orig);
	~Matrice ();
	void init (const double r);
	void affiche (const char *);
	void affiche (std::ofstream &, const char *);
#ifdef MULrenvoieREF
	Matrice& operator*(Matrice& B);
#else
 #ifdef argMULnonConst
	Matrice operator*(Matrice& B);
 #else
	Matrice operator*(const Matrice& B);
 #endif
#endif
	Matrice& operator=(const Matrice& Orig);
	friend void lecmat(std::ifstream &fdon, Matrice &A, int &coderr);
};
#endif

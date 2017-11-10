#ifndef MATRICE4_H
#define MATRICE4_H

class Matrice {
protected:
	int nbl, nbc;
	double **val;
	void allocval (double **&val, int nl, int nc);
	void freeval (double **&val, int nl);
public:
	Matrice(int nl=0, int nc=0);
	virtual ~Matrice ();
	virtual void init (const double r) = 0;
	virtual void affiche (const char *) = 0;
};

// Classe derivee MatSym
// ---------------------

class MatFull;	// Predeclaration a cause de la fonction MatSym::operator* qui
		// renvoie une MatFull et qui est declaree friend dans MatFull

class MatSym: public Matrice {
	void allocval (double **&val, int nl);
public:
	MatSym (int n=0);
	MatSym (const MatSym& Orig);
	virtual void init (const double r);
	virtual void affiche (const char *s);
	MatFull operator*(const MatSym& B);
	MatSym& operator=(const MatSym& Orig);
};

// Classe derivee MatFull
// ----------------------

class MatFull: public Matrice {
public:
	MatFull (int nl=0, int nc=0);
	MatFull (const MatFull& Orig);
	virtual void init (const double r);
	virtual void affiche (const char *s);
	MatFull operator*(const MatFull& B);
	MatFull& operator=(const MatFull& Orig);
// La declaration suivante impose que MatSym soit entierement definie.
	friend MatFull MatSym::operator*(const MatSym& B);
};
#endif

#include "matrice4.h"

#include <iostream>
using namespace std;

// Fonctions membres de la classe MatSym
// -------------------------------------

/*
== Utilitaire d'allocation
*/
void MatSym::allocval (double **&val, int nl) {// Cas d'une matrice symetrique
	val = new double *[nl];
	for (int i=0; i<nl; i++) { val[i] = new double [i+1]; }
	cout << "Allocation cas SYM" << endl;
}
/*
== Constructeur
*/
MatSym::MatSym (int n) : Matrice(n ,n) {
	allocval (val, nbl);
	cout << "Construction. Objet = "<< this<<" val = " << val << endl;
}
/*
== Constructeur par copie en profondeur
*/
MatSym::MatSym (const MatSym& Orig) {
	nbl = Orig.nbl; nbc = Orig.nbc;
	allocval (val, nbl);
        for (int i=0; i<nbl; i++) {
		for (int j=0; j<=i; j++) { val[i][j]=Orig.val[i][j]; }
	}
	cout << "Construction par copie. Objet = "<< this<<" val = " << val << endl;
}
/*
== Initialisation
*/
void MatSym::init (const double r) {
	for (int i=0; i<nbl; i++) {
		for (int j=0; j<=i; j++) { val[i][j]=r; }
	}
}
/*
== Affichage
*/
void MatSym::affiche (const char *s) {
        cout << s << "= " << endl;
        for (int i=0; i< nbl; i++) {
		for (int j=0; j<=i; j++) { cout << " " << val[i][j]; }
        	cout << endl;
	}
}
/*
== Multiplication
*/
MatFull MatSym::operator*(const MatSym& B) {
	int nlr=nbl;
	MatFull resu(nlr,nlr);
	if (nbl != B.nbl) cout << "Dimensions incompatibles." << endl;
	else {
		cout << "Multiplication." << endl;
		int i, j, k;
		double s;
		for (i=0; i<nlr; i++) {
		  for (j=0; j<=i ; j++) {
		    s = 0.;
		    for (k=0; k<=j; k++)
		    	{ s += val[i][k]*B.val[j][k]; }
		    for (; k<=i; k++)
		    	{ s += val[i][k]*B.val[k][j]; }
		    for (; k<nlr; k++)
		    	{ s += val[k][i]*B.val[k][j]; }
		    resu.val[i][j]=s;
		  }
		  for (j=i+1; j<nlr ; j++) {
		    s = 0.;
		    for (k=0; k<=i; k++)
		    	{ s += val[i][k]*B.val[j][k]; }
		    for (; k<=j; k++)
		    	{ s += val[k][i]*B.val[j][k]; }
		    for (; k<nlr; k++)
		    	{ s += val[k][i]*B.val[k][j]; }
		    resu.val[i][j]=s;
		  }
		}
	}
	return resu;
}
/*
== Affectation en profondeur
*/
MatSym& MatSym::operator=(const MatSym& Orig) {
        if (nbl != Orig.nbl) {
		freeval (val, nbl);
                nbl = Orig.nbl; nbc = Orig.nbc;
		allocval (val, nbl);
        }
        for (int i=0; i<nbl; i++) {
		for (int j=0; j<=i; j++) { val[i][j]=Orig.val[i][j]; }
	}
        return *this;
}

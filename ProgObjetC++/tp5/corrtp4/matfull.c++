#include "matrice4.h"

#include <iostream>
using namespace std;

// Fonctions membres de la classe MatFull
// --------------------------------------

/*
== Constructeur
*/
MatFull::MatFull (int nl, int nc) : Matrice(nl, nc) {
	allocval (val, nbl, nbc);
	cout << "Construction. Objet = "<< this<<" val = " << val << endl;
}
/*
== Constructeur par copie en profondeur
*/
MatFull::MatFull (const MatFull& Orig) {
	nbl = Orig.nbl; nbc = Orig.nbc;
	allocval (val, nbl, nbc);
        for (int i=0; i<nbl; i++) {
		for (int j=0; j<nbc; j++) { val[i][j]=Orig.val[i][j]; }
	}
	cout << "Construction par copie. Objet = "<< this<<" val = " << val << endl;
}
/*
== Initialisation
*/
void MatFull::init (const double r) {
	for (int i=0; i<nbl; i++) {
		for (int j=0; j<nbc; j++) { val[i][j]=r; }
	}
}
/*
== Affichage
*/
void MatFull::affiche (const char *s) {
        cout << s << "= " << endl;
        for (int i=0; i< nbl; i++) {
		for (int j=0; j< nbc; j++) { cout << " " << val[i][j]; }
        	cout << endl;
	}
}
/*
== Multiplication
*/
MatFull MatFull::operator*(const MatFull& B) {
	int nlr=nbl, ncr=B.nbc;
	MatFull resu(nlr,ncr);
	if (nbc != B.nbl) cout << "Dimensions incompatibles." << endl;
	else {
		cout << "Multiplication." << endl;
		int i, j, k;
		double s;
		for (i=0; i<nlr; i++) {
		  for (j=0; j<ncr; j++) {
		    s = 0.;
		    for (k=0; k<nbc; k++)
		    	{ s += val[i][k]*B.val[k][j]; }
		    resu.val[i][j]=s;
		  }
		}
	}
	return resu;
}
/*
== Affectation en profondeur
*/
MatFull& MatFull::operator=(const MatFull& Orig) {
        if (nbl != Orig.nbl || nbc != Orig.nbc) {
		freeval (val, nbl);
                nbl = Orig.nbl; nbc = Orig.nbc;
		allocval (val, nbl, nbc);
        }
        for (int i=0; i<nbl; i++) {
		for (int j=0; j<nbc; j++) { val[i][j]=Orig.val[i][j]; }
	}
        return *this;
}

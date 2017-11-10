#include "matrice2.h"

#include <iostream>
using namespace std;

/*
== Constructeur
*/
Matrice::Matrice (int nl, int nc) {
	nbl = nl; nbc = nc;
	val = new double *[nbl];
	for (int i=0; i<nbl; i++) { val[i] = new double [nbc]; }
	cout << "Construction. Objet = "<< this<<" val = " << val << endl;
}
/*
== Destructeur
*/
Matrice::~Matrice () {
	cout << "Destruction. Objet = "<< this<<" val = " << val << endl;
	for (int i=0; i<nbl; i++) { delete [] (val[i]); }
	delete [] val;
}
/*
== Initialisation
*/
void Matrice::init (const double r) {
	for (int i=0; i<nbl; i++) {
		for (int j=0; j<nbc; j++) { val[i][j]=r; }
	}
}
/*
== Affichage
*/
void Matrice::affiche (const char *s) {
        cout << s << "= " << endl;
        for (int i=0; i< nbl; i++) {
		for (int j=0; j< nbc; j++) { cout << " " << val[i][j]; }
        	cout << endl;
	}
}
/*
== Multiplication
*/
Matrice Matrice::operator*(Matrice& B) {
	int nlr=nbl, ncr=B.nbc;
	Matrice resu(nlr,ncr);
	if (nbc != B.nbl) cout << "Dimensions incompatibles." << endl;
	else {
		cout << "Multiplication." << endl;
		int i, j, k;
		double s;
		for (i=0; i<nlr; i++) {
		  for (j=0; j<ncr; j++) {
		    s = 0.;
		    for (k=0; k<nbc; k++) {
		    	s += val[i][k]*B.val[k][j];
		    }
		    resu.val[i][j]=s;
		  }
		}
	}
	return resu;
}

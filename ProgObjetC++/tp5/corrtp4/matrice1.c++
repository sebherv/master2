#include "matrice1.h"

#include <iostream>
using namespace std;

/*
== Constructeur
*/
Matrice::Matrice (int nl, int nc) {
	nbl = nl; nbc = nc;
	val = new double *[nbl];
	for (int i=0; i<nbl; i++) { val[i] = new double [nbc]; }
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
	if (nbc != B.nbl) {
		cout << "Dimensions incompatibles." << endl;
	}
	else {
		cout << "Multiplication." << endl;
	}
	return resu;
}

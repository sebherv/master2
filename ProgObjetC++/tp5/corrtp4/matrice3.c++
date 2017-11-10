#include "matrice3.h"

#include <iostream>
using namespace std;

/*
== Utilitaires d'allocation - liberation
*/
void Matrice::allocval (double **&val, int nl, int nc) {
	val = new double *[nl];
	for (int i=0; i<nl; i++) { val[i] = new double [nc]; }
}
void Matrice::freeval (double **&val, int nl) {
	for (int i=0; i<nl; i++) { delete [] (val[i]); }
	delete [] val;
}
/*
== Constructeur
*/
Matrice::Matrice (int nl, int nc) {
	nbl = nl; nbc = nc;
	allocval (val, nbl, nbc);
	cout << "Construction. Objet = "<< this<<" val = " << val << endl;
}
/*
== Constructeur par copie en profondeur
*/
Matrice::Matrice (const Matrice& Orig) {
	nbl = Orig.nbl; nbc = Orig.nbc;
	allocval (val, nbl, nbc);
        for (int i=0; i<nbl; i++) {
		for (int j=0; j<nbc; j++) { val[i][j]=Orig.val[i][j]; }
	}
	cout << "Construction par copie. Objet = "<< this<<" val = " << val << endl;
}
/*
== Destructeur
*/
Matrice::~Matrice () {
	cout << "Destruction. Objet = "<< this<<" val = " << val << endl;
	freeval (val, nbl);
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
	cout << "Affichage de l'objet " << s << " d'adresse = " << this << endl;
        cout << s << "= " << endl;
        for (int i=0; i< nbl; i++) {
		for (int j=0; j< nbc; j++) { cout << " " << val[i][j]; }
        	cout << endl;
	}
}
/*
== Multiplication
*/
#ifdef MULrenvoieREF
Matrice& Matrice::operator*(Matrice& B) {
	int nlr=nbl, ncr=B.nbc;
	Matrice *presu = new Matrice(nlr,ncr);
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
		    presu->val[i][j]=s;
		  }
		}
	}
	return *presu;
}
#else
#ifdef argMULnonConst
Matrice Matrice::operator*(Matrice& B) {
#else
Matrice Matrice::operator*(const Matrice& B) {
#endif
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
		    for (k=0; k<nbc; k++)
		    	{ s += val[i][k]*B.val[k][j]; }
		    resu.val[i][j]=s;
		  }
		}
	}
	return resu;
}
#endif

/*
== Affectation en profondeur
*/
Matrice& Matrice::operator=(const Matrice& Orig) {
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

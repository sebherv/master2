#include "matrice4.h"

#include <iostream>
using namespace std;

// Fonctions membres communes
// --------------------------

/* 
== Constructeur
*/
Matrice::Matrice(int nl, int nc){
	nbl=nl; nbc=nc;
}

/*
== Utilitaires d'allocation - liberation
*/
void Matrice::allocval (double **&val, int nl, int nc) {// Cas d'une matrice pleine
	val = new double *[nl];
	for (int i=0; i<nl; i++) { val[i] = new double [nc]; }
}
void Matrice::freeval (double **&val, int nl) {
	for (int i=0; i<nl; i++) { delete [] (val[i]); }
	delete [] val;
}
/*
== Destructeur
*/
Matrice::~Matrice () {
	cout << "Destruction. Objet = "<< this<<" val = " << val << endl;
	freeval (val, nbl);
}

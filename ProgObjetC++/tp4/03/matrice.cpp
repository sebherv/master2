#include "matrice2.h"
#include <iostream>
#include <cassert>

using namespace std;


// Constructeur
Matrice::Matrice(int nl, int nc) : nbl(nl), nbc(nc) {
	// Allouer le tableau
	val = new double*[nl];

	for(int i = 0; i < nl; i++) {
		val[i]= new double[nc];
	}
}

// Destructeur
Matrice::~Matrice() {
	// D'abord desallouer les lignes
	for(int i = 0; i < nbl; i ++) {
		delete[] val[i];
	}

	delete[] val;
}

void Matrice::affiche() {
	cout << "[" << endl;
	for(int i = 0; i < nbl; i++) {
		for(int j = 0; j < nbc; j++) {
			cout << val[i][j] << " ";
		}
		cout << endl;
	}
	cout << "]" << endl;
}

Matrice Matrice::operator*(Matrice& other) {
	// Check that matrices are compatible
	assert(this->nbc == other.nbl);

	Matrice result(this->nbl, other.nbc);

	return result;

}


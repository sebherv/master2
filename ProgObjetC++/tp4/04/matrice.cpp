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

void Matrice::allocate() {
	this->allocate();
}

// Destructeur
Matrice::~Matrice() {
	this->cleanUp();
}

// Cleanup
void Matrice::cleanUp() {
	// D'abord desallouer les lignes
	for(int i = 0; i < nbl; i ++) {
		delete[] val[i];
	}
	// puis le tableau de lignes
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

/*Matrice& Matrice::operator=(Matrice& other) {
	if((this->nbl != other.nbl) || (this->nbc != other.nbc)) {
		this->cleanUp();
		this->nbl = other.nbl;
		this->nbc = other.nbc;
		this->allocate();
	}

	// ensuite copier les valeurs une à une.
} */

Matrice Matrice::operator*(Matrice& other) {
	// Check that matrices are compatible
	assert(this->nbc == other.nbl);

	Matrice result(this->nbl, other.nbc);

	return result;
}


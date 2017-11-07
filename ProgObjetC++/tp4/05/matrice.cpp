#include "matrice4.h"
#include <iostream>
#include <cassert>

using namespace std;

// Constructeur par defaut
Matrice::Matrice() {
	// Do not allocate, juste
	// set the size to 0
	val = NULL;
	nbl = 0;
	nbc = 0;

	// Operator=() will have to allocate
	// if necessary
}

// Constructeur
Matrice::Matrice(int nl, int nc) : nbl(nl), nbc(nc) {
	this->allocate();
}


// Destructeur
Matrice::~Matrice() {
	this->cleanUp();
}

void Matrice::allocate() {
	// Allouer le tableau
	val = new double*[nbl];

	for(int i = 0; i < nbl; i++) {
		val[i]= new double[nbc];
	}
}

// Cleanup
void Matrice::cleanUp() {

	// D'abord desallouer les lignes
	// Covers case where nbl == 0
	for(int i = 0; i < nbl; i ++) {
		delete[] val[i];
	}

	// puis le tableau de lignes
	if(val != NULL) {
		delete[] val;
	}
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

Matrice& Matrice::operator=(const Matrice& other) {
	if((this->nbl != other.nbl) || (this->nbc != other.nbc)) {
		this->cleanUp();
		this->nbl = other.nbl;
		this->nbc = other.nbc;
		this->allocate();
	}

	// ensuite copier les valeurs une à une.
} 

Matrice Matrice::operator*(const Matrice& other) {
	// Check that matrices are compatible
	assert(this->nbc == other.nbl);

	Matrice result(this->nbl, other.nbc);

	return result;
}


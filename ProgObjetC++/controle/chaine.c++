#include "chaine.h"
#include <iostream>

chaine::chaine(const char tab[], int nbchar) {

	c = new char[nbchar];
	lc = nbchar;
	for(int i = 0; i < nbchar; i++) {
		c[i] = tab[i];
	}
}

chaine::chaine(const chaine& copy) {
	this->lc = copy.lc;

	c= new char[lc];
	for(int i = 0; i < lc; i++) {
		this->c[i] = copy.c[i];
	}
}

chaine::~chaine() {
	delete[] c;
}

void chaine::print() {
	std::cout << c << std::endl;
}
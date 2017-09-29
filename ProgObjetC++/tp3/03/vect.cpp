#include "vect1.h"
#include <iostream>
#include <cassert>

using namespace std;


Vect::Vect(int n) {
	lg = n;
	val = new double[n];
}

void Vect::init(double initValue) {
	for(int i = 0; i < lg; i++) {
		val[i] = initValue;
	}
}

void Vect::affiche() {
	cout << "Vect " << this << " ";
	for(int i = 0; i < lg ; i++) {
		cout << " x" << i << "= " << val[i];
	}
	cout << endl;
}

void Vect::modif(int i, double r) {
	assert((i >=0) || (i < lg));
	val[i] = r;
}
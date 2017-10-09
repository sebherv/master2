#include "vect3.h"
#include <iostream>
#include <cassert>

using namespace std;


Vect::Vect(int n) {
	lg = n;
	val = new double[n];
}

Vect::Vect(const Vect& vect) {
	this->lg = vect.lg;
	val = new double[lg];
	for(int i = 0; i < lg; i++) {
		this->val[i] = vect.val[i];
	}
}

Vect::~Vect() {
	delete[] val;
}

Vect& Vect::operator=(const Vect& vect) {
	// Delete old if necessary
	if(this->lg != vect.lg) {
		delete[] val;
		val = new double[lg];
	}
	
	this->lg = vect.lg;
	for(int i = 0; i < lg; i++) {
		this->val[i] = vect.val[i];
	}
	return *this;
}

Vect Vect::operator+(const Vect& rhs) {
	assert(this->lg == rhs.lg);
	Vect C(this->lg);
	C.init(0);

	for(int i = 0; i < this->lg; i++) {
		C.val[i]=this->val[i]+rhs.val[i];
	}

	return C;
}

void Vect::init(double initValue) {
	for(int i = 0; i < lg; i++) {
		val[i] = initValue;
	}
}

void Vect::affiche() {
	cout << "Vect " << this << " ";
	cout << "lg=" << lg << "; val=" << val << " ";
	for(int i = 0; i < lg ; i++) {
		cout << " x" << i << "= " << val[i];
	}
	cout << endl;
}

void Vect::modif(int i, double r) {
	assert((i >=0) || (i < lg));
	val[i] = r;
}

void Vect::add(const Vect& A, const Vect& B) {
	assert(this->lg == A.lg);
	assert(this->lg == B.lg);

	for(int i = 0; i < this->lg; i++) {
		this->val[i] = A.val[i] + B.val[i];
	}
}
#include "vect1.h"

#include <iostream>
using namespace std;


Vect::Vect (int n):lg(n) {
	val = new double [lg];
}

void Vect::init (double r) {
	for (int i=0; i< lg; i++) { val[i]=r; }
}

void Vect::affiche (const char *s) {
	cout << s << "= ";
	for (int i=0; i< lg; i++) { cout << " " << val[i]; }
	cout << endl;
}

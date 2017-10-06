#include "vect3.h"
#include <iostream>


using namespace std;

double * getval(const Vect& U) {
	return U.val;
}

int main() {
	Vect a(6);
	a.init(8);

	Vect b(6);
	b.init(18);

	Vect c(6);
	c.init(0);

	cout << "Vector a:" << endl;
	a.affiche();

	cout << "Vector b:" << endl;
	b.affiche();

	c = a + b;

	cout << "Vector c = a + b" << endl;
	c.affiche();

	Vect d(6);
	d.add(a,b);

	cout << "Vector d.add(a,b)" << endl;
	d.affiche();

	Vect E(6);
	int n = 6;

	//E = a+n;
	cout << "Vector e = a+n (n int)" << endl;
	E.affiche();
}
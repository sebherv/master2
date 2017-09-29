#include "vect2.h"
#include <iostream>


using namespace std;

double * getval(const Vect& U) {
	return U.val;
}

int main() {
	Vect v(3);
	v.init(0.5);
	v.affiche();
	cout << "Setting x1=1.0" << endl;
	v.modif(1, 1.0);
	v.affiche();

	cout << "pointeur of v.val: " << getval(v) << endl;
}
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

	Vect U(3);
	U.modif(0,1.0);
	U.modif(1,2.0);
	U.modif(2,3.0);
	double * myVal = getval(U);

	cout << "Les valeurs de U:" << endl;
	for(int i = 0 ; i < 3; i++) {
		cout << "x" << i << "= " << myVal[i] << endl;
	}
}
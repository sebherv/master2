#include "vect1.h"
#include <iostream>


using namespace std;

int main() {
	Vect v(3);
	v.init(0.5);
	v.affiche();
	cout << "Setting x1=1.0" << endl;
	v.modif(1, 1.0);
	v.affiche();

	cout << endl << "Instantiation de v2=Vect(v)" << endl;

	Vect v2(v);
	v2.affiche();

	cout << endl << "Instantiation de v3=v";
	Vect v3 = v;
	v3.affiche();
}
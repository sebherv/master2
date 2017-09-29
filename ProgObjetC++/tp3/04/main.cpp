#include "vect2.h"
#include <iostream>


using namespace std;

int main() {
	Vect v(3);
	v.init(0.5);
	v.affiche();
	cout << "Setting x1=1.0" << endl;
	v.modif(1, 1.0);
	v.affiche();

	cout << endl << "Instantiation de Vect u=v;" << endl;

	Vect u = v;
	u.affiche();

	cout << endl << "Modification de u.x0 = 2" << endl;
	u.modif(0, 2.0);
	u.affiche();

	cout << "Vérification de v" << endl;
	v.affiche();
}
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

	cout << endl << "Instantiation de Vect u;" << endl;

	Vect u;
	u.affiche();
	cout << endl << "Affectation u=v" << endl;
	u=v;
	u.affiche();

	cout << endl << "Modification de u.x0 = 2" << endl;
	u.modif(0, 2.0);
	u.affiche();

	cout << "Vérification de v" << endl;
	v.affiche();



	cout << endl << endl;

	Vect V(3);
	V.init(2);

	cout << "Nouveau vecteur V:" << endl;
	V.affiche();

	cout << endl << "Instantation Vect U,W;" << endl;
	Vect U,W;
	U.affiche();
	W.affiche();

	cout << endl << "Affectation W=U=V" << endl;

	W=U=V;

	U.affiche();
	W.affiche();
}
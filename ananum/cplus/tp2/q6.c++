#include "cercle.h"

#include <iostream>
using namespace std;

int main()
{
	Point P;
	cout << "P cree." << endl;
	Cercle C1(P,2.);
	cout << "C1 cree." << endl;
	/* Dans l'operation precedente, il y a aussi creation du centre,
	transmission de P (constr. par copie) puis destruction de cette copie */

	Cercle C2(11,22,3);
	cout << "C2 cree." << endl;
	C2.affiche();

	C2.dilate(2.2);
	C2.affiche();
}

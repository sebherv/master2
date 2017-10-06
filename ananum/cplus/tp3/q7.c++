#include "vect2.h"

#include <iostream>
using namespace std;

double *getval(const Vect& U) {return U.val;}

int main (void)
{
        double *p;

	{
	cout << "\nDeclaration de U et initialisation" << endl;
	Vect U(5); U.init(111); U.affiche("U"); p=getval(U);
	}
	cout << "Acces aux valeurs via le pointeur de U :" << endl;
	for (int i=0; i<5; i++) { cout << p[i] << " "; }
	cout << endl;
	
	cout << "\nNouveau vecteur :" << endl;
	Vect V(3); V.init(123); V.affiche("V");
	cout << "Acces aux valeurs via le pointeur de U :" << endl;
	for (int i=0; i<5; i++) { cout << p[i] << " "; }
	cout << endl;

}

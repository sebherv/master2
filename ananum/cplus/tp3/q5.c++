#include "vect2.h"

#include <iostream>
using namespace std;

int main (void)
{
        Vect V(3); V.init(123); V.affiche("V");

	cout << "\nDeclaration de U avec initialisation par affectation de V" << endl;
	cout << "(appel du constructeur par copie)" << endl;
	Vect U=V; U.affiche("U");
	
	cout << "Apres modification du 2eme element de U : " << endl;
	U.modif(1,200); U.affiche("U"); V.affiche("V");
}

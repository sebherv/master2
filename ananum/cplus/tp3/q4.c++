#include "vect2.h"

#include <iostream>
using namespace std;

int main (void)
{
        Vect V(3); V.init(12.3);

	cout << "\nDeclaration de U" << endl;
	Vect U; U.affiche("U"); V.affiche("V");
	
	cout << "Apres modification du 2eme element de U : " << endl;
	U.modif(1,200); U.affiche("U"); V.affiche("V");

	cout << "Apres affectation U=V; puis modification du 2eme element de U,\n";
	cout << "les 2 vecteurs ont les memes valeurs :" << endl;
	U=V;
	U.modif(1,300); U.affiche("U"); V.affiche("V");
}

#include "vect1.h"

#include <iostream>
using namespace std;

int main (void)
{
        Vect V(3);
	
	V.init(3.45);	V.affiche("V");
	cout << "Apres modification du 2eme element par modif :" << endl;
	V.modif(1,40000.);	V.affiche("V");

	cout << "Apres re-modification du 2eme element par [] :" << endl;
	V[1]=30000.;	V.affiche("V");

	cout << "\nDeclaration de U avec initialisation par copie de V" << endl;
	Vect U(V);	U.affiche("U");
	cout << "Apres modification du 2eme element de U, les 2 vecteurs "
	<< "ont les memes valeurs :" << endl;
	U.modif(1,44.); // ou U[1]=44.;
	U.affiche("U");
	V.affiche("V");

	cout << "\nDeclaration de W avec initialisation par copie de V (2e syntaxe)" << endl;
	Vect W=V;	W.affiche("W");
	cout << "Apres modification du 2eme element de W, les 2 vecteurs "
	<< "ont les memes valeurs :" << endl;
	W.modif(1,-567); // ou W[1]=-567;
	W.affiche("W");
	V.affiche("V");

}

#include "vect2.h"

#include <iostream>
using namespace std;

int main (void)
{
        Vect V(3); V.init(123); V.affiche("V");

	cout << "\nDeclaration de U et initialisation..." << endl;
	Vect U(5); U.init(111); U.affiche("U");
	cout << "... puis reinitialisation par U = V" << endl;
	U=V; U.affiche("U");

	cout << "\nDeclaration de W et initialisation..." << endl;
	Vect W(8); W.init(7.7); W.affiche("W");
	cout << "... puis reinitialisation par W = U = V" << endl;
	W=U=V; W.affiche("W"); U.affiche("U");
}
/*
   La fonction operator= pourrait ne rien renvoyer (void) si l'utilisation
   etait reduite a U=V;
   L'expression W=U=V; necessite l'enchainement de 2 appels a cette fonction,
   d'ou le retour d'une auto-reference. Cela fonctionnerait aussi avec un retour
   par valeur (Vect au lieu de Vect&), mais au prix d'une copie qui justement
   peut etre evitee par un retour par reference.
   Par defaut, l'evaluation se fait de droite a gauche. Une expression exotique
   telle que (W=U)=V; contrarie cet ordre d'evaluation et le resultat est different
   selon le type de retour :
    . par valeur (Vect) : W devient U, puis affectation de V a un objet temporaire
    . par reference (Vect&) : W devient U, puis W devient V,
   mais dans les deux cas, U reste inchange.
*/

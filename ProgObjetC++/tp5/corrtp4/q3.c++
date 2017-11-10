#include "matrice2.h"

#include <iostream>
using namespace std;

int main (void) {
	cout << "***************************************************************" << endl
	     << "Avertissement :" << endl
	     << "Compte tenu de la definition actuelle de la classe Matrice, il" << endl
	     << "est normal que l'execution de ce programme provoque une erreur."
	     << endl
	     << "***************************************************************" << endl;
	Matrice A(2,3); A.init(1.); A.affiche("A");
	Matrice B(3,2); B.init(2.); B.affiche("B");
	Matrice C(A);  C.affiche("C");
	Matrice D; D=A*B;  D.affiche("D");
}

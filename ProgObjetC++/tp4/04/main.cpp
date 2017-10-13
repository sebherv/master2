#include "matrice2.h"

int main() {

	Matrice a(2,2);
	a.affiche();

	Matrice b(2,4);
	b.affiche();

	Matrice e = a*b;
	e.affiche();

	
}
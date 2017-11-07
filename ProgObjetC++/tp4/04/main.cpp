#include "matrice2.h"

void q4a() {


	Matrice a(3,2);
	a.affiche();

	Matrice b(2,4);
	b.affiche();

	Matrice e;
	e = a*b;
	e.affiche();
}

void q4b() {

	Matrice A(3,3);
	A.affiche();

	Matrice B(3,3);
	B.affiche();

	Matrice G = A*B*A;
	G.affiche();

	Matrice H = A*(B*A);

}

int main() {
	q4b();
	
}
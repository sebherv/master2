#include "matrice1.h"

int main (void) {
	Matrice A(2,3); A.affiche("A");
	Matrice B(3,2); B.affiche("B");
	Matrice C; C=A*B;  C.affiche("C");
	Matrice D; D=B*A;  D.affiche("D");
}

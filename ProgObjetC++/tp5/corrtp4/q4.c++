/* La bonne solution ne necessite aucune macro et
   correspond donc aux deux #define suivants commentes. */
//#define MULrenvoieREF
#ifndef MULrenvoieREF
// #define argMULnonConst /* Pour voir l'erreur de compilation en G=A*(B*A); */
#endif

#include "matrice3.h"


int main (void) {
	Matrice A(2,3); A.init(1.); A.affiche("A");
	Matrice B(3,2); B.init(2.); B.affiche("B");
	Matrice C(A);  C.affiche("C");
	Matrice D; D=A*B;  D.affiche("D");
	Matrice E=B*A;  E.affiche("E");

// Test d'associativite
        Matrice F; F=A*B*A; F.affiche("F=A*B*A");
	Matrice G; G=A*(B*A); G.affiche("G=A*(B*A)");
}

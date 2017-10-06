#include "cercle.h"

#include <iostream>
using namespace std;

int main()
{
	float x1=10, y1=0, x2=0, y2=20, x3=3, y3=3;

	Cercle C(0,0,1);
	cout <<"Cercle C  : "; C.affiche();

// L'instruction suivante provoque une erreur de compilation :
//	Cercle C1 = C.translate_(x1,y1).translate_(x2,y2).translate_(x3,y3);
// On remplace par :
	Cercle C1(C);
	C1.translate_(x1,y1); C1.translate_(x2,y2); C1.translate_(x3,y3);
	cout <<"Cercle C  : "; C.affiche();
	cout <<"Cercle C1 : "; C1.affiche();

	Cercle C2 = C.translateR(x1,y1).translateR(x2,y2).translateR(x3,y3);
	cout <<"Cercle C  : "; C.affiche();
	cout <<"Cercle C2 : "; C2.affiche();

	Cercle C3 = C.translateN(x1,y1).translateN(x2,y2).translateN(x3,y3);
	cout <<"Cercle C  : "; C.affiche();
	cout <<"Cercle C3 : "; C3.affiche();
}

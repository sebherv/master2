#include "point.h"

#include <iostream>
using namespace std;

int main (void)
{
//	Point P1(-1); // Provoque un message du type :
		     // point.h:3: failed assertion `ok()' Abort
	
	Point P;
	P.affiche();

	float x, y;
	cout << "Donner les composantes de translation x et y : ";
	cin >> x >> y;
	P.translate(x,y);	
	P.affiche();
}

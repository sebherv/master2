#include "point.h"

#include <iostream>
using namespace std;

int main (void)
{
        Point P(11,22), Q;
	cout << "Point P :" << endl; P.affiche(); // Constructeur de conversion
	cout << "Point Q :" << endl; Q.affiche(); // Constructeur par defaut

// En C++, l'ordre des instructions est (presque) quelconque de sorte qu'on
// peut creer un point au cours de l'execution comme ceci :
        float x,y;
	cout << "Donner x et y : "; cin >> x >> y ;
	Point R(x,y); R.affiche ();

}

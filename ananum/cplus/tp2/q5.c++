#include "point.h"

#include <iostream>
using namespace std;

int main()
{
	Point P(12.,13.); P.affiche ();
	{
	Point R(10.,20.); R.affiche ();
	Point *S=new Point(20.,30.); S->affiche (); // destructeur non appele
						    // en sortie de bloc
	}
	Point *Q=new Point(22.,23.); Q->affiche (); delete Q;
}

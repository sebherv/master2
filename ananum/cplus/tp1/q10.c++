#include "point.h"

#include <iostream>
using namespace std;

int main (void)
{
        Point P(10,20);
	
	P.affiche ();
	cout << "Distance = " << P.distance() << endl;
}

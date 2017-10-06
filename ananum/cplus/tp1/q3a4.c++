#include "point.h"

#include <iostream>
using namespace std;

int main (void)
{
        Point P(11,22);
	// Ce qui suit a un sens si les donnees membres sont publiques.
	cout << "x=\t" << P.xP << endl;
	cout << "y=\t" << P.yP << endl;
}

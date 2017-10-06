#include "point.h"

#include <iostream>
using namespace std;

Point::Point(float x, float y) {
        xP=x; yP=y;
        cout << "Creation de Point" << endl;
        }
void Point::affiche (void) {
        cout << "x=\t" << xP << ", \t y=\t" << yP << endl;
        }
Point::~Point () {
	cout << "Destruction du Point " ;
	affiche ();
	}
void Point::translate(float x, float y) {
	xP += x;
	yP += y;
	}

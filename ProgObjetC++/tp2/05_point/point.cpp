#include "point.h"
#include <iostream>

using namespace std;

Point::Point(float x=1., float y=2.) {
	xP = x;
	yP = y;
	cout << "Creation de Point " << this << endl;
}

Point::~Point() {
	cout << "Destruction de Point " << this << endl;
}

void Point::affiche() {
	cout << "x=\t" << xP << ", \t y=\t" << yP << endl;
}

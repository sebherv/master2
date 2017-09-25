#include "cercle.h"
#include "point.h"
#include <iostream>
using namespace std;

Cercle::Cercle() {
	cout << "Default Cercle constructor called on " << this << endl;
}

Cercle::Cercle(Point centre, float rayon) {
	mRayon = rayon;
	mCentre = centre;
	cout << "Cercle Constructor 1 called on " << this << endl;
}

Cercle::Cercle(float xc, float yc, float rayon) {
	mRayon = rayon;
	mCentre = Point(xc, yc);
	cout << "Cercle Constructor 2 called on " << this << endl;
}

void Cercle::affiche() {
}

void Cercle::dilate( float facteur) {
}

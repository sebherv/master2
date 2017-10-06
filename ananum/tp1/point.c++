#include "point.h"

#include <cmath>    // pour sqrt
#include <assert.h> // pour assert (necessaire avec certains compilateurs)
#include <iostream>
using namespace std;


Point::Point():xP(1.), yP(2.) {assert(ok());}

Point::Point(float x, float y) {
	xP=x; yP=y;
	assert(ok());
	}
void Point::affiche (void) {
	cout << "x=\t" << xP << ", \t y=\t" << yP << endl;
	}
void Point::affichePointRef (void) {
	PointRef.affiche ();
	}
void Point::modPointRef (float x, float y) {
	PointRef.xP=x; PointRef.yP=y;
	// ou bien : PointRef = Point(x,y);
	assert(PointRef.ok()); // assert(ok()); serait une erreur car le test
			       // porterait alors sur l'instance courante
	}
void Point::translate (float x, float y) {
	xP+=x; yP+=y;
	assert(ok()); // Ici, c'est bien l'instance courante qu'il faut tester
	}
bool Point::ok () {
	return xP>=0. && yP>=0.;
	}
float Point::distance () {
	float u=xP-PointRef.xP, v=yP-PointRef.yP;
	return sqrt(u*u+v*v);
	}

Point Point::PointRef(1.,1.);

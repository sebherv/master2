#include "cercle.h"

#include <iostream>
using namespace std;

// Pour comparaison avec et sans liste d'initialisation :
Cercle::Cercle (Point C, float R) : centre(C), rayon(R) {}
//Cercle::Cercle (Point C, float R) {centre=C; rayon = R;}

Cercle::Cercle (float xc, float yc, float R) : centre(xc,yc) {
	rayon = R;
	}
void Cercle::affiche(void) {
	cout << " Cercle de rayon " << rayon << " et de centre ";
	centre.affiche();
	}
void Cercle::dilate (float F) {
	rayon *= F;
	}
void Cercle::translate_ (float x, float y) {
	centre.translate(x,y);
	}
Cercle& Cercle::translateR (float x, float y) {
	centre.translate(x,y);
	return *this;
	}
Cercle Cercle::translateN (float x, float y) {
	Cercle Clocal(centre,rayon);
	Clocal.centre.translate(x,y);
	return Clocal;
	}

#ifndef CERCLE_H
#define CERCLE_H
#include "point.h"

class Cercle {
	Point centre;
	float rayon;
public :
	Cercle (Point C, float R);
	Cercle (float xc, float yc, float R);
	void affiche(void);
	void dilate (float F);
	void translate_ (float x, float y);
	Cercle& translateR (float x, float y);
	Cercle translateN (float x, float y);
};
#endif

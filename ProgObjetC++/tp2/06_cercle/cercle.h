#ifndef CERCLE_H
#define CERCLE_H

#include "point.h"

class Cercle {
	private:
		Point mCentre;
		float mRayon;
		
	public:
		Cercle();
		Cercle(Point centre, float rayon);
		Cercle(float xc, float yc, float rayon);
		void affiche();
		void dilate( float facteur);
};

#endif

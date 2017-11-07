#ifndef MAJMIN_H
#define MAJMIN_H

#include "chaine.h"

class majus : public chaine {
public:
	majus(const char tab[], int nbcar=0);
	
};

class minus : public chaine {
public:
	minus(const char tab[], int nbcar=0);
};



#endif
#include "majmin.h"
#include <ctype.h>


majus::majus(const char tab[], int nbcar): chaine(tab, nbcar) {
	for(int i = 0; i < lc; i++) {
		c[i]=toupper(c[i]);
	}
}


minus::minus(const char tab[], int nbcar): chaine(tab, nbcar) {
	for(int i = 0; i < lc; i++) {
		c[i]=tolower(c[i]);
	}
}
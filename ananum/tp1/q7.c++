#include "point.h"

int main (void)
{
        Point P, Q;
	
	P.affichePointRef ();
	P.modPointRef(2.33,4.55);
	Q.affichePointRef ();

// Appel direct :
	Point::affichePointRef (); // OK car declare static
//	Point::modPointRef(2.33,4.55);  // Pas OK car non declare static
}

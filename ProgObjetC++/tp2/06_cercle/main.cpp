#include "cercle.h"
#include "point.h"
#include <iostream>

using namespace std;

int main() {
	cout << endl << "instantiation Point sur la stack" << endl;
	Point centre(1,1);
	
	cout << endl << "instantion Cercle sur la stack" << endl;
	Cercle cercle(centre, 10.);
	
	cout << endl << "Fin de Programme" << endl;
}

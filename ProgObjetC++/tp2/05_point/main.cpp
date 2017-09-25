#include "point.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Instantiation classique sur la pile..." << endl;
	Point pointClassique(1,1);
	
	cout << "Creation / allocation par new d'un point..." << endl;
	Point * allocatedPoint = new Point(3,3);
	Point * allocatedPoint2 = new Point(4,4); 
	
	{
		cout << "Instanciation classique sur la pile dans un bloc" << endl;
		Point pointClassique(2,2);
	}
	cout << "Après la fin de bloc ... " << endl;
	
	cout << "Sur le point de détruire " << allocatedPoint << "..." << endl;
	delete(allocatedPoint);
	
}

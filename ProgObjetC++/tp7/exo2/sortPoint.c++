#include "point.h"
#include <vector>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;


bool pointComparator(Point* i, Point* j) {
	return (i->getL2Norm() < j->getL2Norm());
}

class pointComparatorClass {
	public:
		bool operator() (Point* i, Point* j) {return (i->getL2Norm() < j->getL2Norm());}
} comparator;

struct pointComparatorStruct {
	bool operator() (Point* i, Point* j) {return (i->getL2Norm() < j->getL2Norm());}
} compstruct;

int main() {

	// Créer une liste de points
	std::vector<Point*> v;
	srand (time(NULL));

	int i = 10;
	while(i-- > 0) {
		v.push_back(new Point(rand()%10,rand()%10));
	}

	vector<Point*>::iterator it;
	for(it=v.begin(); it!=v.end(); it++) {
		(*it)->affiche();
	}

	sort(v.begin(), v.end(), [](Point* i, Point* j) {return (i->getL2Norm() < j->getL2Norm());} );
	cout << "After sort(): " << endl;

	for(it=v.begin(); it!=v.end(); it++) {
		(*it)->affiche();
	}



	// clean up v
	for(it=v.begin(); it!=v.end(); it++) {
		delete *it;
	}
}
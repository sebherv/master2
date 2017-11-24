#include "Vec.h"
#include <iostream>

Vec::Vec(int i):std::vector<double>(i) {}

void Vec::init(double val) {
	Vec::iterator it;
	for(it=begin(); it!=end(); it++){
		*it = val;
	}
}

void Vec::affiche() {
	Vec::iterator it;
	for(it=begin(); it!=end();it++) {
		std::cout << *it << std::endl;
	}
}

Vec Vec::operator+(const Vec& V) const {
	Vec aggregate(0);

	Vec::const_iterator it;

	for(it=begin(); it!=end(); it++) {
		aggregate.push_back(*it);
	}

	for(it=V.begin(); it!=V.end(); it++) {
		aggregate.push_back(*it);
	}

	return aggregate;

}
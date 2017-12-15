#include "vec_f.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vec_f::vec_f(int n) : V(n) {
	V.assign(n,n);
}

void vec_f::print() {
	vector<float>::iterator it;
	for(it=V.begin(); it!=V.end(); it++) {
		cout << *it << endl;
	}
}
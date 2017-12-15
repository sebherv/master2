#include <vector>
#include <complex>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using std::vector;
using std::complex;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;

vector<complex<float> > lecvec(ifstream& is) {

	vector<complex<float> > V(0);

	istream_iterator<float> lecV(is);
	istream_iterator<float> fin;

	while(lecV != fin) {
		// Lire 2 float
		float real = *lecV;
		lecV++;
		float imag = *lecV;
		lecV++;

		// Créer le complex
		complex<float> newComplex(real,imag);
		V.push_back(newComplex);
	}

	return V;

}

bool complexComparator(complex<float> i, complex<float> j) {
	return (abs(i) < abs(j));
}

void dumpVector(vector<complex<float> > V ) {
	vector<complex<float> >::iterator it;
	for(it=V.begin(); it!=V.end(); it++) {
		cout << *it << endl;
	}
}

int main() {

	// init the input stream
	ifstream filestream("couples");

	vector<complex<float> > V = lecvec(filestream);

	cout << "Avant le tri:" << endl;
	dumpVector(V);

	// Sort
	sort(V.begin(),V.end(),complexComparator);

	cout << endl << "Après le tri: " << endl;
	dumpVector(V);

}
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


template<typename T>
vector<complex<T> > lecvec(ifstream& is) {

	vector<complex<T> > V(0);

	istream_iterator<T> lecV(is);
	istream_iterator<T> fin;

	while(lecV != fin) {
		// Lire 2 T
		T real = *lecV;
		lecV++;
		T imag = *lecV;
		lecV++;

		// Créer le complex
		complex<T> newComplex(real,imag);
		V.push_back(newComplex);
	}

	return V;

}

template<typename T>
bool complexComparator(complex<T> i, complex<T> j) {
	return (abs(i) < abs(j));
}

template<typename T>
void dumpVector(vector<complex<T> > V ) {
	typename vector<complex<T> >::iterator it;
	for(it=V.begin(); it!=V.end(); it++) {
		cout << *it << endl;
	}
}

template<typename T>
void test() {

	// init the input stream
	ifstream filestream("couples");

	vector<complex<T> > V = lecvec<T>(filestream);
	cout << "Avant le tri:" << endl;
	dumpVector<T>(V);
	sort(V.begin(),V.end(),complexComparator<T>);
	cout << endl << "Après le tri: " << endl;
	dumpVector<T>(V);

}

int main() {

	cout << "Cas FLOAT:" << endl;
	test<float>();

	cout << endl << "Cas DOUBLE: " << endl;
	test<double>();

}
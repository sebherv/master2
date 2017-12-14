#include "Vec.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

template<typename T>
void testVec(T initFisrt, T initSecond) {
	Vec<T> first(initFisrt, 5);
	Vec<T> second(initSecond, 5);
	cout << "after objects instanciations" << endl;

	Vec<T> result = first+second;

	cout << "after addition" << endl;
	result.affiche();
}

int main() {
	cout << "testing with int: 3 + 7 :" << endl;
	testVec<int>(3,7);

	cout << "testing with double: 5.3 + 8.5:" << endl;
	testVec<double>(5.3,8.5);

	cout << "testing with strings: toto + tata:" << endl;
	testVec<string>("toto", "tata");
	
}
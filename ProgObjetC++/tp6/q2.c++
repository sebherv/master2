#include <vector>
#include <iostream>

using std::vector;


template<class T> void somme(vector<T>& A, vector<T>& B, vector<T>& C) {
	typename vector<T>::iterator itA;
	typename vector<T>::iterator itB;

	itA=A.begin();
	itB=B.begin();

	while((itA != A.end()) || (itB != B.end())) {
		T topush = 0;
		if(itA != A.end()) {
			topush += *itA;
			itA++;
		}
		if(itB != B.end() ) {
			topush += *itB;
			itB++;
		}
		C.push_back(topush);
	}

}

void testInt() {
	int tab1[] = {1,2,3,4,5,6,7,8,9};
	int tab2[] = {9,8,7,6,5,4};

	vector<int> intA(tab1, tab1+9);
	vector<int> intB(tab2, tab2+6);
	vector<int> resultInt(0);

	somme(intA, intB, resultInt);

	vector<int>::iterator it;
	std::cout << "contenu resultInt: " << std::endl;
	for(it=resultInt.begin(); it != resultInt.end(); it++) {
		std::cout << *it << "; ";
	}
	std::cout << std::endl;
}

void testDouble() {
	double tab1[] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	double tab2[] = {9.9,8.8,7.7,6.6,5.5,4.4};

	vector<double> doubleA(tab1, tab1+9);
	vector<double> doubleB(tab2, tab2+6);
	vector<double> resultdouble(0);

	somme(doubleA, doubleB, resultdouble);

	vector<double>::iterator it;
	std::cout << "contenu resultdouble: " << std::endl;
	for(it=resultdouble.begin(); it != resultdouble.end(); it++) {
		std::cout << *it << "; ";
	}
	std::cout << std::endl;

}

int main() {
	testInt();
	testDouble();
}
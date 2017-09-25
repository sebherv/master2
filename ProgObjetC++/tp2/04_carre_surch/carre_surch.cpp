#include <iostream>

using namespace std;

float carre(float numf) {
	return numf * numf;
}

void carre(float* numfp) {
	float tempf = *numfp * *numfp;
	*numfp = tempf;
	return;
}

void carreByRef(float &numr) {
	float tempf = numr * numr;
	numr = tempf;
	return;
}

int main () {
	float num;
	cout << "Saisir un nombre (float): ";
	cin >> num;
	
	float * numptr; 
	float numpted;
	numptr = &numpted;
	
	float numref = num;
	*numptr = num;
	
	cout << endl;
	cout << "Valeur de num passée à carre(num): " << num << endl;
	cout << "Résultat avec carre(): " <<  carre(num) << endl << endl; 
	
	cout << "*numptr avant appel à carre(numptr): " << *numptr << endl;
	carre(numptr);
	cout << "*numptr après appel à carre(numptr): " << *numptr << endl << endl;
	
	cout << "numref avant appel à carreByRef(numref): " << numref <<endl;
	carreByRef(numref);
	cout << "numref après appel à carreByRef(numref): " << numref << endl << endl;


}

#include <iostream>

using namespace std;

float carreV(float numf) {
	return numf * numf;
}

void carreP(float* numfp) {
	float tempf = *numfp * *numfp;
	*numfp = tempf;
	return;
}

void carreR(float &numr) {
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
	cout << "Valeur de num passée à carreV(): " << num << endl;
	cout << "Résultat avec carreV(): " <<  carreV(num) << endl << endl; 
	
	cout << "*numptr avant appel à carreP(): " << *numptr << endl;
	carreP(numptr);
	cout << "*numptr après appel à carreP(): " << *numptr << endl << endl;
	
	cout << "numref avant appel à carreR(): " << numref <<endl;
	carreR(numref);
	cout << "numref après appel à carreR(): " << numref << endl << endl;


}

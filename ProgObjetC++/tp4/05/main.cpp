#include "matrice2.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void q4a() {


	Matrice a(3,2);
	a.affiche();

	Matrice b(2,4);
	b.affiche();

	Matrice e;
	e = a*b;
	e.affiche();
}

void q4b() {

	Matrice A(3,3);
	A.affiche();

	Matrice B(3,3);
	B.affiche();

	Matrice G = A*B*A;
	G.affiche();

	Matrice H = A*(B*A);

}

void q5() {
	string inputfile;
	inputfile = "input.txt";
	ifstream inputstream(inputfile.c_str());

	// We will extract 2 matrices;
	Matrice * inputMatrixArray[2];

	for(int i = 0 ; i < 2; i++) {
		// Read first line
		int row, col;
		inputstream >> row;
		inputstream >> col;
		for(int j = 0; j < row; j++) {
			for() 
		}
	}

}

int main() {
	q5();
	
}
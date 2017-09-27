#include <iostream>
#include <stdlib.h>
#include "matrix.h"

using namespace std;



int main()
{
	// init rand() seed
	srand (time(NULL));


	int m;
	int n;
	/*// Saisir taille de la matrice A
	cout << "m= ? ";
	cin >> m;
	cout << "n= ? ";
	cin >> n; */
	
	for(int i = 100; i <=400; i*=2) {
		
		m=n=i;
		// Initialiser 2 matrices
		Matrix * a = new Matrix(m,n);
		Matrix * b = new Matrix(n,m);
	
		/*cout << "Matrix a is:" << endl;
		a->dumpToCout();
		cout << endl;

		cout << "Matrix b is:" << endl;
		b->dumpToCout(); */

		// Multiply the 2 matrics
		Matrix * r = Matrix::multiply(a,b);

		/*cout << "Matrix r = a * b is: " << endl;
		r->dumpToCout();
		*/
	}
}


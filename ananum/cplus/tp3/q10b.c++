#include "prodb.h"

#include <iostream>
using namespace std;

/*
   Si la fonction est definie dans le .h, le compilateur dispose de tous les
   elements pour fabriquer le code necessaire.
   
   Ici, on a un seul fichier .c++ :
    g++ q10b.c++
*/

int main (void)
{
// Types homogenes
        int i=2, j=3, k=prod(i,j);
	cout << i << " x " << j << " = " << k << endl;
        float fi=2.2, fj=3.3, fk=prod(fi,fj);
	cout << fi << " x " << fj << " = " << fk << endl;
        double di=12.2, dj=13.3, dk=prod(di,dj);
	cout << di << " x " << dj << " = " << dk << endl;

// Conversion degradante du resultat (warning)
	int kk=prod(fi,fj);
	cout << fi << " x " << fj << " = " << kk << endl;

// Types heterogenes
	k=prod(i,fj); // (warning)
	cout << i << " x " << fj << " = " << k << endl;
	fk=prod(fi,j);
	cout << fi << " x " << j << " = " << fk << endl;
	fk=prod(fi,dj);
	cout << fi << " x " << dj << " = " << fk << endl;
	dk=prod(di,j);
	cout << di << " x " << j << " = " << dk << endl;
	fk=prod(di,j);
	cout << di << " x " << j << " = " << fk << endl;
}

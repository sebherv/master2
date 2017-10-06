#include "proda.h"

#include <iostream>
using namespace std;

/*
   Dans le cas de la compilation separee, c'est a dire repartition de la
   declaration dans un .h et de l'implementation dans un .c++, une solution consiste
   a instancier la fonction (dans le .c++) pour tous les cas d'appels differents,
   ce qui peut etre impossible en pratique.

   Ici on a deux fichiers .c++ :
    g++ q10a.c++ proda.c++
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

}

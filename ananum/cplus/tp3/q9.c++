#include "vect3.h"

#include <iostream>
using namespace std;

int main (void)
{
        Vect A(3); A.init(2); A.affiche("A");
	Vect B(3); B.init(3); B.affiche("B");

/* Lors de l'operation suivante, il y a creation d'un objet temporaire resultat
   sur la pile qui est recupere par l'operateur d'affectation (qui est surcharge).
   Cet objet est donc recopie dans C puis detruit. */
	Vect C(3); C.init(0); C=A+B;      C.affiche("C");

/* Lors de l'operation suivante, le resultat est directement affecte dans la
   memoire associee a D : cette version est donc plus efficace que la precedente,
   mais elle offre une ecriture moins agreable. */ 
	Vect D(3); D.init(0); D.add(A,B); D.affiche("D");

	int n=2;
	Vect E(3); E.init(0);
/* Ci-dessous, n est converti implicitement en un Vect grace au constructeur Vect(int).
   Pour empecher cela, ajouter  explicit  devant dans vect3.h. */ 
	E=A+n;
	E.affiche("E");

cout << "FIN\n";
}

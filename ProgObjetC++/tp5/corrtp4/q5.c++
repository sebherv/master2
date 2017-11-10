/*
La solution proposee ci-dessous passe par la definition d'une fonction
externe, lecmat, donc declaree friend dans la classe Matrice.
On pourrait aussi en faire une fonction membre de la classe Matrice, ce
qui assurerait un acces direct aux donnees membres.
Enfin, on pourrait surcharger l'operateur d'extraction operator>> avec le
prototype : istream& operator>>(istream&, Matrice&);
La aussi, il faudrait declarer cette fonction friend dans la classe Matrice.
*/

#include "matrice3.h"

#include <fstream>
#include <cstdlib> // pour la fonction exit
using namespace std;

/*	---------------------------------------------------------------
	Lecture de la matrice A dans le fichier fdon.
	En cas d'erreur sur les dimensions, coderr est non nul en retour.
	Declare friend dans la classe Matrice.
	---------------------------------------------------------------*/
void lecmat(ifstream &fdon, Matrice &A, int &coderr) {
	int nbl, nbc;
	fdon >> nbl >> nbc;
	if (nbl < 1 || nbc < 1) {
		cerr << "Dimensions  incorrectes. Abandon." <<endl;
		coderr=1;
	}
	else {
// Pour eviter la matrice temporaire T, on pourrait aussi
// reprendre la meme programmation que dans operator=.
		Matrice T(nbl, nbc);
		for (int i=0; i<nbl; i++) {
			for (int j=0; j<nbc; j++)
				{ fdon >> T.val[i][j]; }
		}
		A=T; // Affectation en profondeur
		coderr=0;
	}
}

/*   -------------------------------------------------------------------------
	Surcharge de la fonction membre affiche pour
	imprimer la matrice s dans le fichier Fic.
 --> Cette fonction doit normalement figurer dans le fichier d'implementation
     de la classe Matrice, matrice3.c++ dans la cas present. Ce n'est pas fait
     ici volontairement pour ne pas trop melanger les themes des differentes
     questions du TP.
     -------------------------------------------------------------------------*/
void Matrice::affiche (ofstream &Fic, const char *s) {
        Fic << s << "= "<< endl;
        for (int i=0; i< nbl; i++) {
		for (int j=0; j< nbc; j++) { Fic << " " << val[i][j]; }
        	Fic << endl;
	}
}

//------------------------------------------------------------------------------
int main (void) {
	const int nx=20;
	char tmp[nx];
	string ficdon("q5.don"), ficres("q5.res");

// Lecture des noms des fichiers de donnees et resultat.
// Si on tape RETURN, on accepte la valeur par defaut proposee.
	cout << "Nom du fichier de donnees [" << ficdon << "] : ";
	cin.getline(tmp,nx); if (cin.gcount() > 1) ficdon = tmp;

	cout << "Nom du fichier resultat [" << ficres << "] : ";
	cin.getline(tmp,nx); if (cin.gcount() > 1) ficres = tmp;
	
// Ouverture du flot d'entree. On teste si le fichier de donnees existe bien.
	ifstream fdon(ficdon.c_str());
	if (! fdon) {
		cout << "Fichier " << ficdon << " inexistant. abandon." << endl;
		exit(1);
	}

// Ouverture du flot de sortie
	ofstream fres(ficres.c_str());

// Lecture des matrices, calcul du produit et impression du resultat dans
// le fichier resultat. En cas de donnees invalides, le programme s'arrete.	
	int coderr;
	Matrice A;
	lecmat(fdon, A, coderr); if (coderr) exit(1);
	fres << "Le produit de la matrice" << endl;
	A.affiche(fres,"A");
	
	Matrice B;
	lecmat(fdon, B, coderr); if (coderr) exit(1);
	fres << "et de la matrice" << endl;
	B.affiche(fres,"B");

	Matrice C=A*B;
	fres << "est" << endl;
	C.affiche(fres,"C");
}

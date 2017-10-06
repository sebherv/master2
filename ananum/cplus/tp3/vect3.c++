#include "vect3.h"

#include <iostream>
using namespace std;

Vect::Vect (int n):lg(n) {
	val = new double [lg];
}

// Constructeur par copie en profondeur
Vect::Vect (const Vect& V) {
//	cout << "Constructeur par copie" << endl;
	lg=V.lg; val = new double [lg];
	for (int i=0; i< lg; i++) { val[i]=V.val[i]; }
}

// Destructeur
Vect::~Vect () {
	delete [] val;
	cout << "  DESTRUCTION\n";
}

void Vect::init (double r) {
	for (int i=0; i< lg; i++) { val[i]=r; }
}

// Affectation en profondeur
Vect& Vect::operator=(const Vect& V) {
	if (lg != V.lg) {
		delete [] val;
		lg = V.lg; val = new double [lg];
	}
	for (int i=0; i< lg; i++) { val[i]=V.val[i]; }
	return *this;
}

// Affichage
void Vect::affiche (const char *s) {
	cout << "lg= " << lg <<"  val= " << val << "\t";
	cout << s << "= ";
	for (int i=0; i< lg; i++) { cout << " " << val[i]; }
	cout << endl;
}

// Addition : operateur
Vect Vect::operator+(const Vect& B) {
	int lgB = B.lg; // On suppose que les vecteurs de meme taille
	Vect resu(lgB);
	for (int i=0; i< lgB; i++) { resu.val[i] = val[i] + B.val[i]; }
	return resu;
}

// Addition : fonction membre
void Vect::add (const Vect& A, const Vect& B) {
			// On suppose que les vecteurs de meme taille
	for (int i=0; i< B.lg; i++) { val[i] = A.val[i] + B.val[i]; }
}

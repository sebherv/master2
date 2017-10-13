#include "matrice1.h"




int main() {
	Matrice m(3,2);
	m.affiche();

	Matrice v(2,1);
	v.affiche();

	Matrice res = m*v;
	res.affiche();
}
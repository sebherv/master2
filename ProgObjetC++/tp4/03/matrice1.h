#ifndef MATRICE_H
#define MATRICE_H

class Matrice {
private: 
	int nbl;
	int nbc;
	double ** val;

public:
	// Constructeurs
	Matrice(int nl, int nc);

	// Operateurs
	Matrice operator*(Matrice& other);

	// Autres
	void affiche();

};

#endif
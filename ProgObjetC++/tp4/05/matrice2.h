#ifndef MATRICE_H
#define MATRICE_H

class Matrice {
private: 
	int nbl;
	int nbc;
	double ** val;

	// Private member functions
	void cleanUp();
	void allocate();

public:
	// Constructeurs / Destruceur
	Matrice();
	Matrice(int nl, int nc);
	~Matrice();

	// Operateurs
	Matrice& operator=(const Matrice& other);
	Matrice operator*(const Matrice& other);

	// Autres
	void affiche();

};

#endif
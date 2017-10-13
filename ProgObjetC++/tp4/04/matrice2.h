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
	Matrice(int nl, int nc);
	~Matrice();

	// Operateurs
	//Matrice& operator=(Matrice& other);
	Matrice operator*(Matrice& other);

	// Autres
	void affiche();

};

#endif
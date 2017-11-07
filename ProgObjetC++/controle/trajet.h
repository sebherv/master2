#include <string>
#ifndef TRAJET_H
#define TRAJET_H


class trajet {
	std::string nom;
	float distance, // en km
	      duree;	// en mn

public:
	trajet(std::string n = std::string("def"), float di = 1.0, float du = 1.0);
	void print();

	void modur(float delta);
	trajet ajout(float delta);

	trajet operator+(float delta);
	trajet operator+(trajet& other);
};

#endif
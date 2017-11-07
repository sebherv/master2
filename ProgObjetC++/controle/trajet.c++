#include "trajet.h"
#include <iostream>


trajet::trajet(std::string n, float di, float du): nom(n), distance(di), duree(du) {
}

void trajet::print() {
	std::cout << "Nom : " << nom;
	std::cout << " " << distance << " Km, ";
	std::cout << " " << duree << " mn." << std::endl;
}

void trajet::modur(float delta) {
	duree += delta;
}

trajet trajet::ajout(float delta) {
	trajet C(nom, distance, duree);
	C.modur(delta);
	return C;
}

trajet trajet::operator+(float delta) {
	trajet C(nom, distance, duree);
	C.modur(delta);
	return C;
}

trajet trajet::operator+(trajet& other) {
	trajet sum(this->nom + other.nom, this->distance + other.distance, this->duree + other.duree);
	return sum;
}
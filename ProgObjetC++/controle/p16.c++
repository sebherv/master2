#include "trajet.h"
#include <iostream>

int main() {
	trajet T(std::string("Paris-Lyon"), 467, 276);
	std::cout << "Objet original" << std::endl;
	T.print();

	std::cout << "invocation de ajout()" << std::endl;
	T.ajout(-28).print();

	std::cout << "Verification que l'objet original n'est pas modifié" << std::endl;
	T.print();
}
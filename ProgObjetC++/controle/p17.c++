#include "trajet.h"
#include <iostream>

int main() {
	trajet T(std::string("Paris-Lyon"), 467, 276);
	std::cout << "Objet original" << std::endl;
	T.print();

	std::cout << "invocation de l'operateur +" << std::endl;
	trajet mod = T + 65;
	mod.print();

	std::cout << "Verification que l'objet original n'est pas modifié" << std::endl;
	T.print();
}
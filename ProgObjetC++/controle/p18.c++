#include "trajet.h"
#include <iostream>

int main() {
	trajet T(std::string("Paris-Lyon"), 467, 276);
	trajet U(std::string("Lyon-Marseille"), 400, 300 );
	std::cout << "Objets originaux" << std::endl;
	T.print();
	U.print();

	std::cout << "invocation de l'operateur +" << std::endl;
	trajet mod = T + U;
	mod.print();

	std::cout << "Verification que les objets originaux ne sont pas modifiés" << std::endl;
	T.print();
	U.print();
}
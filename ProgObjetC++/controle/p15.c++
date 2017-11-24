#include "trajet.h"
#include <iostream>

int main() {
	trajet T(std::string("Paris-Lyon"), 467, 276);
	std::cout << "Avant modification" << std::endl;
	T.print();

	T.modur(-15);
	std::cout << "Après modification de durée" << std::endl;
	T.print();
} 
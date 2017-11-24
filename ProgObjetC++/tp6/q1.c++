#include <iostream>
#include <vector>

void affiche(std::vector<double> & V, int n) {
	for(int i = n; i > 0; i--) {
		std::cout << V.at(i) << std::endl;
	}
}

void affiche(std::vector<double> & V) {
	std::vector<double>::iterator it;
	
	for(it = V.begin(); it != V.end(); it++) {
		std::cout << *it << std::endl;
	}
}



int main() {
	std::vector<double> v(10, 3.1);

	std::cout << "Version par indices: " << std::endl;
	affiche(v,6);


	std::cout << std::endl;
	std::cout << "Version par iterator: " << std::endl;
	affiche(v);
}
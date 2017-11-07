#include "trajet.h"
#include <fstream>
#include <string>

int main() {
	// Ouvrir le fichier
	std::ifstream fdon("trajet.don");

	while(!fdon.eof()) {
		std::string currentName;
		float currentDist;
		float currentDuree;

		fdon >> currentName;
		fdon >> currentDist;
		fdon >> currentDuree;

		trajet t(currentName, currentDist, currentDuree);
		t.print();
	}
}
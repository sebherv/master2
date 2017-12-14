#include "Vec.h"
#include <string>

using std::string;

int main() {
	Vec<double> v(10);
	v.init(53.2);
	v.affiche();

	Vec<int> vint(10);
	vint.init(64);
	vint.affiche();

	Vec<string> vstring(10);
	vstring.init("toto");
	vstring.affiche();
}
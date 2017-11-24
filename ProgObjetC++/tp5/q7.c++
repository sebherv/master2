#include "Vec.h"

int main() {
	Vec v(10);

	v.init(53.2);

	Vec u(5);
	u.init(23.4);

	Vec result = u+v;

	result.affiche();
}
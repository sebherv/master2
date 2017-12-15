#include "vec_base.h"
#include "vec_t.h"
#include "iostream"

using std::cout;
using std::endl;

int main() {

	vec_t<float> Vf(10);
	vec_t<double> Vd(5);
	vec_t<int>	Vi(3);

	vec_base* array[3];
	array[0] = &Vf;
	array[1] = &Vd;
	array[2] = &Vi;
	// Invocation du polymorphisme
	cout << "vec_t<float> Vf(10)" << endl;
	array[0]->print();

	cout << endl << "vec_t<double> Vd(5)" << endl;
	array[1]->print();

	cout << endl << "vec_t<int>	Vi(3)" << endl;
	array[2]->print();

}
#include "vec_base.h"
#include "vec_f.h"



int main() {

	vec_f V(10);

	vec_base& W = V;

	// Invocation du polymorphisme
	W.print();
}
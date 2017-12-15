#ifndef VEC_F_H
#define VEC_F_H
#include "vec_base.h"
#include <vector>


class vec_f : public vec_base {
private:
	std::vector<float> V;

public:
	vec_f(int n);
	virtual void print();
};


#endif
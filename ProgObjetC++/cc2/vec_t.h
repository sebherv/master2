#ifndef VEC_T_H
#define VEC_T_H
#include "vec_base.h"
#include <iostream>
#include <vector>

template<typename T>
class vec_t : public vec_base {
private:
	std::vector<T> V;

public:
	vec_t(int n);
	virtual void print();
};


template<typename T>
vec_t<T>::vec_t(int n) : V(n) {
	V.assign(n,n);
}


template<typename T>
void vec_t<T>::print() {
	typename std::vector<T>::iterator it;
	for(it=V.begin(); it!=V.end(); it++) {
		std::cout << *it << std::endl;
	}
}


#endif
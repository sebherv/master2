#ifndef VEC_H
#define VEC_H
#include <vector>

class Vec : std::vector<double> {
public:
	Vec(int i);
	void init(double val);
	void affiche();

	Vec operator+(const Vec& V) const;
};

#endif
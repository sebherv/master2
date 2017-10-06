#ifndef VECT1_H
#define VECT1_H

class Vect {
	int lg;
	double *val;
public:
	Vect (int n);
	void init (double r);
	void affiche (const char *);
	inline void modif(int i, double r) {val[i] = r;}

	inline double& operator[](int i) {return val[i];}
};
#endif

#ifndef VECT2_H
#define VECT2_H

class Vect {
	int lg;
	double *val;
public:
	Vect (int n=0);
	Vect (const Vect&);
	void init (double r);
	void affiche (const char *);
	inline void modif(int i, double r) {val[i] = r;}
	Vect& operator=(const Vect& V);
	friend double *getval(const Vect& U);
};
#endif

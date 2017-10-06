#ifndef VECT3_H
#define VECT3_H

class Vect {
	int lg;
	double *val;
public:
	explicit Vect (int n=0);
	Vect (const Vect&);
	~Vect ();
	void init (double r);
	void affiche (const char *);
	inline double& operator[](int i) {return val[i];}
	Vect& operator=(const Vect& V);
	Vect operator+(const Vect& B);
	void add (const Vect& A, const Vect& B);
	friend double *getval(const Vect& U);
};
#endif

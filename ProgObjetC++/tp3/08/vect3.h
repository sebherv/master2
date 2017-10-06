#ifndef VECT1_H
#define VECT1_H

class Vect {
private:
	int lg;
	double * val;

public:
	Vect(int n=0);
	Vect(const Vect& vect);
	~Vect();
	Vect& operator=(const Vect& vect);


	void init(double initVal);
	void affiche();
	void modif(int i, double r);

	friend double * getval(const Vect& U);
};



#endif
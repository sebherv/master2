#ifndef VECT1_H
#define VECT1_H

class Vect {
private:
	int lg;
	double * val;

public:
	Vect(int n);
	void init(double initVal);
	void affiche();
	void modif(int i, double r);
};



#endif
#ifndef VECT1_H
#define VECT1_H

class Vect {
private:
	int lg;
	double * val;

public:
	explicit Vect(int n=0);
	Vect(const Vect& vect);
	~Vect();
	Vect& operator=(const Vect& vect);
	Vect  operator+(const Vect& rhs);


	void init(double initVal);
	void affiche();
	void modif(int i, double r);

	void add(const Vect& A, const Vect& B);

	friend double * getval(const Vect& U);
};



#endif
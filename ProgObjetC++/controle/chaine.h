#ifndef CHAINE_H
#define CHAINE_H

class chaine {

protected:
	int lc;
	char * c;

public:
	chaine(const char tab[], int nbchar=0);
	chaine(const chaine& copy);
	~chaine();

	virtual void print();

};

#endif
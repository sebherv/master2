#include <iostream>

using namespace std;

class Matrix
{
private:

	double * mBuffer;
	int m;
	int n;

	int getIndex(int i, int j) { return i * m + j;}

public:
	Matrix();
	Matrix(int mInput, int nInput);
	~Matrix();
	static Matrix * multiply(Matrix * a, Matrix * b);
	double getCij(int i, int j);
	void setCij(int i, int j, double value);
	void initRandom();

	void dumpToCout();

};
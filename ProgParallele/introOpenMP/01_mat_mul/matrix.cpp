#include <iostream>
#include <stdlib.h>
#include "matrix.h"

#ifdef _OPENMP
#include "omp.h"
#endif

using namespace std;

Matrix::Matrix()
{
	m = n = 0;
}

Matrix::Matrix(int mInput, int nInput)
{
	m = mInput;
	n = nInput;

	mBuffer = (double*)malloc(sizeof(double) * m * n);
	this->initRandom();
}

Matrix::~Matrix()
{
	free(mBuffer);
}

// This method is static
Matrix * Matrix::multiply(Matrix * a, Matrix * b)
{
	// check that both matrixes are compatible
	if(a->m != b->n)
	{
		cout << "Matrix::multiply() ERROR: matrices are not compatible for multiplication." << endl;
		return NULL;
	}

	int kMax = a->m;
	int iMax = a->n;
	int jMax = b->m;

	Matrix * toReturn = new Matrix(iMax, jMax);

	//Perform matrix multiplication
	#ifdef _OPENMP
	#pragma omp parallel for
	for(int i=0; i < iMax; i++)
	{
		for(int j=0; j < jMax; j++)
		{
			double tempValue = 0;
			// Multiply column from a with line from b
			for(int k = 0; k < kMax; k++) {
				tempValue += a->getCij(i,k) * b->getCij(k,j); 
			}
			toReturn->setCij(i,j,tempValue);
		}
	}
	#endif

	return toReturn;
}

void Matrix::initRandom()
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			this->setCij(i,j,rand() % 10);
		}
	}
}

double Matrix::getCij(int i, int j)
{
	return mBuffer[getIndex(i,j)];
}

void Matrix::setCij(int i, int j, double value)
{
	mBuffer[getIndex(i,j)] = value;
}

void Matrix::dumpToCout()
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(j != 0) { cout << " , ";}
			cout << getCij(i,j) ;
		}
		cout << endl;
	}
}



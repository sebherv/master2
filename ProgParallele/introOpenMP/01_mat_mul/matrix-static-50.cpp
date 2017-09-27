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

	mBuffer = new double[m * n];
	this->initRandom();
}

Matrix::~Matrix()
{
	delete[] mBuffer;
}

// This method is static
Matrix * Matrix::multiply(Matrix * a, Matrix * b)
{
	int iterAtEachSize = 10;
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

	for( int threadnum = 1; threadnum <= 4; threadnum++) {
		for(int iter = 0; iter < iterAtEachSize; iter++) {
			omp_set_num_threads(threadnum);
			cout << threadnum << " threads; ";
			cout << iMax << "x" << jMax << "; ";
			//Perform matrix multiplication
			#ifdef _OPENMP
			double t0 = omp_get_wtime();
			#pragma omp parallel for schedule(static,50)
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
			} // for i
			double t1 = omp_get_wtime();
			#endif
			cout << t1-t0 << " wtime() elapsed " <<endl;
		} // for iter
	} // for threadnum

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



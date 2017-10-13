#include <cstdio>

void VecAdd( const float* pA, const float* pB, float* pC, int vectorSize)
{
	for( int i = 0 ; i < vectorSize; ++i)
	{
		pC[i] = pA[i] + pB[i];
	}
}

void VecFill( float * pVector, int vectorSize, float firstValue, float increment )
{
	for( int i = 0 ; i < vectorSize; ++i)
	{
		pVector[i] = firstValue+(increment*i);
	}
}

void VecPrint( const float * pVector, int vectorSize, const char * pLabel="noname" )
{
	printf("%s : \n", pLabel);
	for( int i = 0 ; i < vectorSize; ++i)
	{
		printf("[%d] : %f\n", i, pVector[i]);
	}
}

int main(int argc, char* argv[])
{
	int vectorSize = 10;
	
	size_t vectorMemSize = vectorSize * sizeof(float);
	
	float *pA = (float *)malloc(vectorMemSize);
	float *pB = (float *)malloc(vectorMemSize);
	float *pC = (float *)malloc(vectorMemSize);
	
	VecFill(pA, vectorSize, 0.0f, 1.0f);
	VecPrint(pA, vectorSize, "A");
	VecFill(pB, vectorSize, 10.0f, -0.5f);
	VecPrint(pB, vectorSize, "B");
	VecAdd(pA, pB, pC, vectorSize);
	VecPrint(pC, vectorSize, "A+B");
	
	free(pA);
	free(pB);
	free(pC);

	return 0;
}


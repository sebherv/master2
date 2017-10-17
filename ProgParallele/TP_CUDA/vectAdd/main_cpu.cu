#include <cstdio>

__global__ void VecAddKernel(float* dA, float* dB, float* dC)
{
	int i = threadIdx.x;
	dC[i] = dA[i] + dB[i];
}

void VecAdd( const float* pA, const float* pB, float *pC, int vectorSize)
{
	size_t vectorMemSize = vectorSize * sizeof(float);
	// Allocate
	float* dA;
	cudaMalloc(	&dA, vectorMemSize );
	float* dB;
	cudaMalloc(	&dB, vectorMemSize );
	float* dC;
	cudaMalloc(	&dC, vectorMemSize );
	//vectors in device memory
	// copy vectors from host memory to device memory
	cudaMemcpy( dA, pA, vectorMemSize, cudaMemcpyHostToDevice);
	cudaMemcpy( dB, pB, vectorMemSize, cudaMemcpyHostToDevice);
	dim3 numBlocks(1,1,1);
	dim3 numThreadsPerBlock(vectorSize,1,1);
	// Kernel invocation
	VecAddKernel<<<numBlocks, numThreadsPerBlock>>>(dA, dB, dC);
	// copy the resulting vector from device memory to host memory
	cudaMemcpy( pC, dC, vectorMemSize, cudaMemcpyDeviceToHost);
	// free device memory
	cudaFree( dA );
	cudaFree( dB );
	cudaFree( dC );
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


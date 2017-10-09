#include <iostream>
#include <stdlib.h> // srand(), rand()
#include "mpi.h"

const int RANK_ROOT = 0;

using namespace std;

int main(int argc, char *argv[])
{

	int worldSize, rank;
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD,&worldSize);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	srand(time(NULL)+rank);

	int N, M = 0;
	float* vect = NULL;
	int numOfLines = 0;

	if(rank == RANK_ROOT) {
		cout << "Vector size ? " ;
		cin >> N; 
		while (M==0) {
			cout << endl << "Matrix line number (must be a multiple of "<< worldSize <<")? ";
			cin >> M;
			if(M % worldSize != 0) {
				M = 0;
				cout << "M is not a multiple of " << worldSize << ".";
			}
		}

		cout << "Just before init vector" << endl;

		// init vector
		vect = new float[N];
		for(int i = 0; i < N; i++) {
			vect[i] = rand()%10;
		}
	}

	if(rank == RANK_ROOT) {
		cout << "Just before MPI_Bcast()" << endl;;
	}
	MPI_Bcast(&N, 1, MPI_INT, RANK_ROOT, MPI_COMM_WORLD);
	MPI_Bcast(&M, 1, MPI_INT, RANK_ROOT, MPI_COMM_WORLD);

	if(rank != RANK_ROOT) {
		vect = new float[N];
	}

	// Broadcast the vector to all vectors first
	MPI_Bcast(vect, N, MPI_FLOAT, RANK_ROOT, MPI_COMM_WORLD);

	if(rank == RANK_ROOT) {
		cout << "Just after MPI_Bcast()" << endl;
	}

	// Init part of matrix for each proc
	// (code here is identical on all process, we will shift
	// the lines at the end according to the rank)
	numOfLines = M / worldSize;

	// init 2D array
	float * matrixBlobForProc = new float[numOfLines * N];
	float ** matrixLine = new float*[numOfLines];
	for(int i = 0; i < numOfLines; i++) {
		matrixLine[i] = &matrixBlobForProc[i*N];
	}

	// Init matrix values
	for(int i = 0; i < numOfLines * N; i++) {
		matrixBlobForProc[i] = rand() % 10;
	}

	// Init result vector part for each process
	// (numOfLine == M / worldsize)
	float * resultVectPart = new float[numOfLines];

	// Perform the multiplication
	for(int i = 0; i < numOfLines; i++) {
		for(int j = 0; j < N; j++) {
			resultVectPart[i]=matrixLine[i][j] * vect[j];
		}
	}

	float * recvdResVector = NULL;

	if(rank == RANK_ROOT) {
		recvdResVector = new float[numOfLines * worldSize];
	} 

	if(rank == RANK_ROOT) {
		cout << "Just before MPI_Gather()" << endl;
	}

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Gather(	resultVectPart, numOfLines, MPI_FLOAT,  // send each resultVectPart ...
				recvdResVector, numOfLines, MPI_FLOAT,  // ... into recvdResVector ...
				RANK_ROOT, MPI_COMM_WORLD);				// ... to RANK_ROOT

	//cout << "hello from rank " << rank << " !!!" << "Vect is " << vect[0] <<endl;

	if(rank == RANK_ROOT) {
		cout << "MatVect multiplication finished; result:" << endl;
		for(int i = 0; i < M; i++) {
			cout << recvdResVector[i] << endl;
		}
	}

	MPI_Finalize();


}

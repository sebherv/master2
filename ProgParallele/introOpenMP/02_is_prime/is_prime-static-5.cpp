#include <iostream>

#ifdef _OPENMP
#include "omp.h"
#endif

using namespace std;

int main()
{
	int iterAtEachSize = 10;
	
	cout << "Veuillez saisir un nombre entier:" << endl;
	int monInt;
	cin >> monInt;
	
	for( int threadnum = 1; threadnum <= 4; threadnum++) {
		for(int iter = 0; iter < iterAtEachSize; iter++) {
			omp_set_num_threads(threadnum);
			cout << threadnum << " threads; ";
			double t0 = omp_get_wtime(); 
			int foundPrimes = 0;
		
			#pragma omp parallel for schedule(static, 5) reduction(+:foundPrimes)
			for(int current = 2; current < monInt; current++) {
				int i = 2;
				bool isPrime = true;
				while(i < current && isPrime) {
					if(current % i == 0) {
						isPrime = false;
					}
					i++;
				}

				if(isPrime) {
					foundPrimes++;
				}
			} // for current
			double t1 = omp_get_wtime();

			cout << "Found " << foundPrimes << " prime numbers between 1 and " << monInt << "; ";
			cout << t1-t0 << " wtime() elapsed " <<endl; 
		}
	}
}

#include <iostream>

using namespace std;

int main()
{
	cout << "Veuillez saisir un nombre entier:" << endl;
	int monInt;
	cin >> monInt;

	int foundPrimesNumber = 0;

	for(int current = 2; current < monInt; current++)
	{
		int i = 2;
		bool isPrime = true;
		while(i < current && isPrime)
		{
			if(current % i == 0) {
				//Not prime
				isPrime = false;
			}
			i++;
		}

		if(isPrime)
		{
			foundPrimesNumber++;
		}
	}

	cout << "Found " << foundPrimesNumber << " prime numbers between 1 and " << monInt << "." << endl;
}
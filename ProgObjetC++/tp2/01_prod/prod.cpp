#include <iostream>

using namespace std;

// forward declaration
int prod(int i, int j);
double prod(double r, double s);

int main() {
	int i, j;
	double r, s;
	float res;
	cout << "Saisir i: (int)";
	cin >> i;
	cout << endl << "Saisir j: (int)";
	cin >> j;
	
	cout << "Saisir r: (double)";
	cin >> r;
	cout << "Saisir s: (double)";
	cin >> s;
	
	cout << "i * j = " << prod(i,j) << endl;
	cout << "r * s = " << prod(r,s) << endl;
	
	res = prod(r,s);
	
	//cout << "i * r = " << prod(i,r) << endl;
}

int prod(int i, int j) {
	return i * j;
}

double prod(double r, double s) {
	return r * s;
}

float prod(double rf, double sf) {
	return rf * sf;
}

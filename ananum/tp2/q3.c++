#include <iostream>
using namespace std;

float carreV(float x) {return x*x;}
void carreP(float *x) {*x = *x**x;}
void carreR(float& x) {x = x*x;}

int main()
{
	float a=2.; 
	cout << carreV(a) << endl;
	carreP(&a); cout << a << endl;
	carreR(a); cout << a << endl;
}

#include <iostream>
using namespace std;

// Il y ambiguite si les 3 trois fonctions portent le meme nom.
// Il suffit de renommer soit la premiere, soit la troisieme. Mais si l'on souhaite
// absolument utiliser la surcharge, il faut alors ajouter un argument supplementaire
// a l'une des deux fonctions.

float carre(float x) {return x*x;}
void carre(float *x) {*x = *x**x;}
void carreR(float& x) {x = x*x;}

int main()
{
	float a=2.; 
	cout << carre(a) << endl;
	carre(&a); cout << a << endl;
	carreR(a); cout << a << endl;
}

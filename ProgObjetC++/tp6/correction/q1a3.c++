#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Affichage des nx premiers elements du vecteur V, version "indice".
template <class T_V> // ou template <typename T_V>
void affiche (T_V & V, int nx) {
	for (int i=0; i<nx; i++) { cout << " " << V[i] ; }
	cout << endl;
}

// Affichage du contenu du vecteur V, version "iterateur".
void affiche (vector<double> & V) {
	vector<double>::iterator i;
	for (i=V.begin(); i != V.end(); i++) { cout << " " << *i ; }
	cout << endl;
}

// Initialisation du vecteur V par lecture de valeurs sur l'entree standard
// via l'utilisation d'un iterateur d'entree-sortie.
void init (vector<double> & V) {
	vector<double>::iterator i;
// L'iterateur suivant permet de reperer la fin des donnees :
	istream_iterator<double> fin;

	cout << "Donner une suite de valeurs terminee par ^D." << endl;
	cout << "Donner une valeur : ";
// L'iterateur suivant permet la lecture de donnees de type double sur cin.
// Il est initialise avec la valeur lue sur cin.
	istream_iterator<double> lecV(cin);

	while (lecV != fin) { // lecture jusqu'a la fin des donnees
		cout << "Donner une valeur : ";
		V.push_back(*lecV); // stockage de la valeur lue precedemment
		lecV++; // nouvelle lecture
	}
	cout << endl;
}

// Somme de deux vecteurs W = U+V
template <class T_U, class T_V, class T_W>
void somme(T_U& U, T_V& V, T_W& W) {
// Precaution : le resultat est de la taille du vecteur le plus court.
	int n=U.size(); if (V.size() < n) n = V.size();
// Reinitialisation de la memoire du resultat
	W.clear();
// Somme
	for (int i=0; i<n; i++)	{ W.push_back(U[i] + V[i]); }
}

//------------------------------------------------------------------------------
int main (void)
{
// Declaration d'un vecteur et initialisation par appel a un iterateur
// d'entree-sortie.
	vector<double> A;
	init (A);
	cout << " La somme du vecteur" << endl;
	affiche (A); // Appel de la version "iterateur"

	const int nx=A.size();
// Declaration d'un vecteur de taille fixee et initialisation par une constante
        vector<int> B(nx,1);
	cout << " et du vecteur" << endl;
	affiche (B,nx); // Appel de la version "indice"

	vector<double> C;
	somme (A,B,C);
	cout << "est : " << endl;
	affiche (C);
}

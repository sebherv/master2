#include <iostream>
#include <vector>
using namespace std;

// g++ -std=c++11 q5.c++

void affiche (const vector<vector<double> > & A) {
  for (auto& i:A) {
    for (auto& j:i) { cout << j << " "; } // (auto j:i)  OK aussi
    cout << endl;
  }
}

int main() {
// Declaration d'une matrice et initialisation par appel a un constructeur.
    vector<vector<double> > A(3, vector<double>(2,4));

    cout << " La matrice est :" << endl;
    affiche(A);

// Declaration d'une matrice et initialisation par initializer-list.
    vector<vector<double> > B{{1,2},{3,4}};

    cout << " La matrice est :" << endl;
    affiche(B);

}

/* La programmation ci-dessous permet d'utiliser la classe Point telle qu'elle
   a ete definie au TP1. Voir cependant les remarques.
*/
#include "../tp1/point.h"

#include <iostream>
#include <vector>       // std::vector
using namespace std;

// Fonction de comparaison externe
bool cmp(Point& A, Point& B) { return A.distance() < B.distance(); }
/*
 Remarque 1.
 Le prototype suivant est preferable :
  bool cmp(const Point& A, const Point& B);
 Cela necessite la presence de const dans le prototype de la fonction Point::distance :
  float distance() const;
*/

// Classe de comparaison (foncteur)
struct ccmp {
  bool operator()(Point& A, Point& B){ return A.distance() < B.distance(); }
};

/*
 Remarque 2.
 Ici aussi, le type devrait etre const vector<Point>&, ce qui necessite le qualifieur
 const dans le prototype de la fonction Point::affiche.
*/
void print(vector<Point>& V, const char* mes) {
  cout << mes << endl;
  for (vector<Point>::iterator it=V.begin(); it!=V.end(); it++) { it->affiche(); }
}

int main(){
  vector<Point> V(3,Point(3,3));
  V[1] = Point(1,1);
  V[2] = Point(2,2);
  print(V,"Avant tri :");

  sort (V.begin(), V.end(), cmp);
  print(V,"Apres tri par fonction externe :");

  sort (V.begin(), V.end(), ccmp());
  print(V,"Apres tri par foncteur :");

/*
  Remarque 3.
  Si l'on s'autorise a modifer la classe Point, alors on peut surcharger l'operateur < :
  bool Point::operator<(const Point& B) const { return distance() < B.distance(); }
  (modifier aussi le prototype de Point::distance, cf. Remarque 1)
  et ainsi realiser le tri par :
  sort (V.begin(), V.end());
*/
}

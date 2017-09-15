#include <iostream>
#include "point.h"

using namespace std;

int main()
{
  Point monPoint;
  double x,y;

  // cout << "Veuillez saisir un x..." << endl;
  // cin >> x;
  // cout << "Veuillez saisir un y..." << endl;
  // cin >> y;

  // Point pointInitialise(x,y);

  // cout << "Contenu du point arbitraire:" << endl;
  // monPoint.affiche();

  // cout << "Contenu du point initialisé:" << endl;
  // pointInitialise.affiche();

  cout << "Contenu de pointRef avant modification" << endl;
  monPoint.affichePointRef();

  cout << "Veuillez saisir un x..." << endl;
  cin >> x;
  cout << "Veuillez saisir un y..." << endl;
  cin >> y;

  monPoint.modPointRef(x,y);

  cout << "Contenu de pointRef après modification:" << endl;
  monPoint.affichePointRef();

  cout << "Veuillez saisir un x pour translater..." << endl;
  cin >> x;
  cout << "Veuillez saisir un y pour translater..." << endl;
  cin >> y;

  monPoint.translate(x,y);

  cout << "Point translaté:" << endl;
  monPoint.affiche();

}

#include <iostream>
using namespace std;

int main()
{
  int monInt;
  double monDouble;

  cout << "Veuillez saisir un nombre entier..." << endl;
  cin >> monInt;

  cout << "Veuillez saisir un nombre réel..." << endl;
  cin >> monDouble;

  double result = monInt + monDouble;

  cout << monInt << " + " << monDouble << " = " << monInt + monDouble;
  cout << endl;
}

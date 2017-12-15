#include "vec.h"
#include <iostream>

int main() {
// Test pour le type double
   Vec<double> Udouble(3);
   Udouble.init(5.5);
   Udouble.affiche();

   Vec<double> Vdouble(3);
   Vdouble.init(2.2);
   Vdouble.affiche();

   Vec<double> Wdouble(Udouble+Vdouble);
   Wdouble.affiche();

// Test pour le type int
   Vec<int> Uint(3);
   Uint.init(5);
   Uint.affiche();

   Vec<int> Vint(3);
   Vint.init(2);
   Vint.affiche();

   Vec<int> Wint(Uint+Vint);
   Wint.affiche();
}

#include "vec.h"
#include <iostream>

// Fonction de test generique. Fonctionne pour tout type pour lequel
// l'operateur += est defini (compte tenu de la definition de la surcharge
// de operator+ dans la classe Vec (cf. vec.c++)).


template <class T>
void ftest(T val1, T val2) {
   Vec<T> UT(3);
   UT.init(val1);
   UT.affiche();

   Vec<T> VT(3);
   VT.init(val2);
   VT.affiche();

   Vec<T> WT(UT+VT);
   WT.affiche();
}

int main() {
   ftest<double>(5.5, 2.2);
   ftest<int>(5,2);
   ftest<std::string>(std::string("abc"),std::string("DEF"));
}

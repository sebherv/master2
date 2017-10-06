#include "proda.h"

// Definition de la fonction template pour les types homogenes
template <class T>
T prod(T a, T b) {return a*b;}

// Instanciations de la fonction pour les types attendus dans le programme test.
// Elles ne seraient pas necessaires si la fonction etait definie dans le .h
// (cf programme q10b.c++).
template int prod(int, int);
template float prod(float, float);
template double prod(double, double);


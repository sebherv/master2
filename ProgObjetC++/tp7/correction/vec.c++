#include "vec.h"
#include <iostream>
using std::cout;
using std::endl;

template <class T>
Vec<T>::Vec(int n):std::vector<T>(n) {}

template <class T>
void Vec<T>::init(T valini) {
  for (int i=0; i<this->size(); i++) {
     (*this)[i] = valini;
  }
}

template <class T>
void Vec<T>::affiche() {
  for (int i=0; i<this->size(); i++) {
     cout << (*this)[i] << " ";
  }
  cout << endl;
}

template <class T>
Vec<T> Vec<T>::operator+(const Vec& V){
   Vec<T> W(*this);
   for (int i=0; i<this->size(); i++) {
     W[i] += V[i];
   }
   return W;
}

// class template instantiations:
template class Vec<double>;
template class Vec<int>;
template class Vec<std::string>;
// Ceci necessite de prevoir tous les types qui doivent etre utilises,
// mais cela autorise un controle sur l'usage de la classe.
// Si on ne le souhaite pas, alors il faut placer l'implementation dans le .h
// apres la declaration de la classe.

#ifndef VEC_H
#define VEC_H
#include <vector>

template <class T>
class Vec : public std::vector<T> {
public:
   Vec(int n);
   void init(T valini);
   void affiche();
   Vec operator+(const Vec& V);
};
#endif

#ifndef VEC_H
#define VEC_H
#include <valarray>
#include <iostream>

template <typename T>
class Vec : public std::valarray<T> {
public:
	Vec(const T& initval, int i);
	Vec(const std::valarray<T>& other);
	//Vec<T> operator+(const Vec<T>& other);
	void affiche();
};

template<typename T>
Vec<T>::Vec(const T& initval, int i):std::valarray<T>(initval,i) {}

template<typename T>
Vec<T>::Vec(const std::valarray<T>& other):std::valarray<T>(other) {}

//template<typename T>
//Vec<T> Vec<T>::operator+(const Vec<T>& other) {
//	std::cout << "adding" << std::endl;
//	typename std::valarray<T> resultValArray = *this+other;//

//	std::cout << "returning" << std::endl;//

//	return Vec<T>(resultValArray);//

//}

template<typename T>
void Vec<T>::affiche() {
	
	for(int i = 0; i < this->size();i++) {
		std::cout << (*this)[i] << std::endl;
	}
}


#endif
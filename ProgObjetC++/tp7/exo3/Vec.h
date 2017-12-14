#ifndef VEC_H
#define VEC_H
#include <vector>
#include <iostream>

template <typename T>
class Vec : std::vector<T> {
public:
	Vec(int i);
	void init(T val);
	void affiche();
	Vec operator+(const Vec& V) const;
};

template<typename T>
Vec<T>::Vec(int i):std::vector<T>(i) {}

template<typename T>
void Vec<T>::init(T val) {
	typename Vec<T>::iterator it;
	for(it=this->begin(); it!=this->end(); it++){
		*it = val;
	}
}

template<typename T>
void Vec<T>::affiche() {
	typename Vec<T>::iterator it;
	for(it=this->begin(); it!=this->end();it++) {
		std::cout << *it << std::endl;
	}
}

template<typename T>
Vec<T> Vec<T>::operator+(const Vec<T>& V) const {
	Vec<T> aggregate(0);

	typename Vec<T>::const_iterator outterIt;
	typename Vec<T>::const_iterator innerIt;
	innerIt=V.begin();


	for(outterIt=this->begin(); outterIt!=this->end(); outterIt++) {
		if(innerIt != V.end()) {	
			aggregate.push_back(*outterIt+*innerIt);
			innerIt++;
		}
	}

	return aggregate;

}


#endif
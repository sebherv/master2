#include <iostream>
#include <vector>

using std::vector;


void print(vector<vector<double> > matrice) {
	vector<vector<double> >::iterator it;

	for(it=matrice.begin(); it!=matrice.end(); it++) {
		vector<double>::iterator it2;
		for(it2 = it->begin(); it2 != it->end(); it2++) {
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	/*double tab1[] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	vector<vector<double> > matrice;

	for(int i = 0; i < 9; i++) {
		vector<double> current(tab1, tab1+9);
		matrice.push_back(current);
	} */
	vector<vector<double> > matrice(4, vector<double>(5,8));

	print(matrice);


	std::cout << "Element at 1,1: " << matrice[1][1] << std::endl;

}
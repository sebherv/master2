#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int>V(0);

	V.push_back(1515);
	V.push_back(2017);
	V.push_back(1900);
	V.push_back(1802);
	V.push_back(1582);

	vector<int>::iterator it;

	for(it=V.begin(); it!=V.end(); it++) {
		cout << *it << endl;
	}
}
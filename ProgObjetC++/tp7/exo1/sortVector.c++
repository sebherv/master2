#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using std::vector;
using std::list;

void sortVector(int* myArray, int size) {
	vector<int> vec(myArray, myArray+size);

	vector<int>::iterator it;
	std::cout << "vector before sort():" << std::endl;
	for(it=vec.begin(); it!=vec.end(); it++) {
		std::cout << *it << " ";
	}

	sort(vec.begin(),vec.end());

	std::cout << std::endl << "vector after sort():" << std::endl;
	for(it=vec.begin(); it!=vec.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

void sortList(int* myArray, int size) {
	list<int> myList(myArray, myArray+size);

	list<int>::const_iterator it;
	std::cout << "list before sort():" << std::endl;
	for(it=myList.begin(); it!=myList.end(); it++) {
		std::cout << *it << " ";
	}

	//sort(myList.begin(),myList.end());
	myList.sort();

	std::cout << std::endl << "list after sort():" << std::endl;
	for(it=myList.begin(); it!=myList.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

int main() {
	int myArray[] = {12,52,78,63,48,96,14,54};

	sortVector(myArray,8);
	std::cout << std::endl;

	sortList(myArray,8);
}
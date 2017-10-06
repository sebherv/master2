#include <iostream>
using namespace std;

int prod (int i, int j) {return i*j;}
double prod (double i, double j) {return i*j;}
// Oter le commentaire suivant pour la question 2 :
//float prod (double i, double j) {return i*j;}

int main (void)
{
        cout << prod(2,-3) << endl;	
        cout << prod(2.2,-3.3) << endl;
        cout << prod((double)2,-3.3) << endl;	
        float r=3.; cout << prod(r,-3.3) << endl;	
}

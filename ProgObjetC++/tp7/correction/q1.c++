#include <iostream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <set>          // std::set
#include <map>          // std::map
using namespace std;

int main(){
  int data[] = {6, 2, 34, 8, 19, 23};

  vector<int> V(data,data+6);
  sort (V.begin(), V.end());
  cout << "Classe vector apres tri :" << endl;
  for (vector<int>::iterator it=V.begin(); it!=V.end(); it++) { cout << *it << endl; }

  set<int> S(data,data+6);
  cout << "Classe set (tri automatique) :" << endl;
  for (set<int>::iterator it=S.begin(); it!=S.end(); it++) { cout << *it << endl; }

  // L'usage suivant de map revient a ce qui precede, mais en plus complique
  map<int,int> M;
  for (vector<int>::iterator it=V.begin(); it!=V.end(); it++) { M[*it] =  *it; }
  cout << "Classe map (tri automatique selon la cle) :" << endl;
  for (map<int,int>::iterator it=M.begin(); it!=M.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
}

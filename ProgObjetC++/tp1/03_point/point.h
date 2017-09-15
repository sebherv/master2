#include <iostream>
using namespace std;

class Point {
 
 private: double xP, yP;
  static Point pointRef;

 public: 
  Point() {xP = 0; yP = 0; }
  Point(double x, double y);
  ~Point() {};
  void affiche();
  void affichePointRef();
  void modPointRef(double x, double y);
  void translate(double xplus, double yplus);
  bool ok();
};

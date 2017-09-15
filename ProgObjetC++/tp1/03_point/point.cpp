#include <iostream>
#include "point.h"
using namespace std;

Point Point::pointRef(0,0);

Point::Point(double x, double y)
{
  xP = x;
  yP = y;
}

void Point::affiche()
{
  cout << "xP = " << xP << endl;
  cout << "yP = " << yP << endl;
}

void Point::affichePointRef()
{
  pointRef.affiche();
}

void Point::modPointRef(double x, double y)
{
  pointRef.xP = x;
  pointRef.yP = y;
}

void Point::translate(double xplus, double yplus)
{
  assert(ok());
  xP += xplus;
  yP += yplus;
}

bool Point::ok()
{
	if((xP > 0) && (yP > 0))
	{
		return true;
	}
	
	return false;
}

#ifndef POINT_H
#define POINT_H
class Point {
public :
        Point(float x=1., float y=2.);
	void affiche (void);
	~Point ();
	void translate(float x, float y);

private :
        float xP, yP;
};
#endif

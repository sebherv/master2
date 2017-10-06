#ifndef POINT_H
#define POINT_H
class Point {
public :
	Point();
	Point(float x, float y=2.); // Incompatible avec le constructeur par defaut
				    // sans argument si TOUS les arguments ont une
				    // valeur d'initialisation
	void affiche (void);
	static void affichePointRef (void);
	void modPointRef (float x, float y);
	void translate (float x, float y);
	bool ok ();
	float distance ();

private :
	float xP, yP;
	static Point PointRef;
};
#endif

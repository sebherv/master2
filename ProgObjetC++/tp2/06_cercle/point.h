#ifndef POINT_H
#define POINT_H

class Point {
	private:
		float xP, yP;
		
	public:
		Point();
		Point(float x, float y);
		~Point();
		void affiche();
};

#endif

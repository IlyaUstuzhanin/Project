// Classes.h

#ifndef CLASSES_H
#define CLASSES_H

class Point {
public:
	double x, y, z;

	Point();
	Point(double i, double j, double k);
};

class vector {
public:
	double x, y, z;

	vector();

	vector(double i, double j, double k);

	vector(Point a, Point b);

	vector vector_product(vector a, vector b);

	double scalar_product(vector a, vector b);
};

class Cell {
public:
	Point A, B, C, D;
	Point collocation;
	vector n;

	Cell();

	Cell(Point a, Point b, Point c, Point d);

	void collocPoint();

	double norma(vector l);

	void normal();

	double square();
};




#endif // CLASSES_H

#include <iostream>
#include<stdio.h>

using namespace std;

class Point {
public:
	double x, y, z;

	Point() {};
	Point(double i, double j, double k) {
		x = i;
		y = j;
		z = k;
	};
};

class vector {
public:
	double x, y, z;

	vector() {};

	vector(double i, double j, double k) {
		x = i;
		y = j;
		z = k;
	};

	vector(Point a, Point b) {
		x = b.x - a.x;
		y = b.y - a.y;
		z = b.z - a.z;
	}

	vector vector_product(vector a, vector b) {
		double i = a.y * b.z - a.z * b.y;
		double j = a.x * b.z - a.z * b.x;
		double k = a.x * b.y - a.y * b.x;
		vector n(i, j, k);
		return n;
	}

	double scalar_product(vector a, vector b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
};

class Cell {
public:
	Point A, B, C, D;
	Point collocation;
	vector n;

	Cell(Point a, Point b, Point c, Point d) {
		A = a;
		B = b;
		C = c;
		D = d;
		collocPoint();
		normal();
	}
	void collocPoint() {
		collocation.x = 1.0 / 4.0 * (A.x + B.x + C.x + D.x);
		collocation.y = 1.0 / 4.0 * (A.y + B.y + C.y + D.y);
		collocation.z = 1.0 / 4.0 * (A.z + B.z + C.z + D.z);
	};

	double norma(vector l) { return sqrt(l.x * l.x + l.y * l.y + l.z * l.z); }

	void normal() {
		vector l(A, C);
		vector r(B, D);
		n = n.vector_product(l, r);
		double norm = norma(n);
		n.x = n.x / norm;
		n.y = n.y / norm;
		n.z = n.z / norm;
	};

	double square() {
		vector l(A, C);
		vector r(B, D);
		l = l.vector_product(l, r);
		return norma(l) / 2;
	}
};
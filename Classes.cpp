#include <iostream>
#include<stdio.h>
#include "Classes.h"
#include <cmath>

Point::Point() {};
Point::Point(double i, double j, double k) {
	x = i;
	y = j;
	z = k;
};

vector::vector() {};

vector::vector(double i, double j, double k) {
	x = i;
	y = j;
	z = k;
};

vector::vector(Point a, Point b) {
	x = b.x - a.x;
	y = b.y - a.y;
	z = b.z - a.z;
};

vector vector:: vector_product(vector b) {
	double i = y * b.z - z * b.y;
	double j = x * b.z - z * b.x;
	double k = x * b.y - y * b.x;
	vector n(i, j, k);
	return n;
};

double vector::scalar_product( vector b) { return x * b.x + y * b.y + z * b.z; }


Cell::Cell() {};

Cell::Cell(Point a, Point b, Point c, Point d) {
	A = a;
	B = b;
	C = c;
	D = d;
	collocPoint();
	normal();
};
void Cell:: collocPoint() {
	collocation.x = 1.0 / 4.0 * (A.x + B.x + C.x + D.x);
	collocation.y = 1.0 / 4.0 * (A.y + B.y + C.y + D.y);
	collocation.z = 1.0 / 4.0 * (A.z + B.z + C.z + D.z);
};

double vector::norma() { return std::sqrt(x * x + y * y + z * z); };

void Cell::normal() {
	vector l(A, C);
	vector r(B, D);
	n = l.vector_product(r);
	double norm = n.norma();
	n.x = n.x / norm;
	n.y = n.y / norm;
	n.z = n.z / norm;
};

double Cell:: square() {
	vector l(A, C);
	vector r(B, D);
	l = l.vector_product(r);
	return l.norma() / 2.0;
};
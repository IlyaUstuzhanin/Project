// Geomtery.h

#ifndef GEOMETRY_H
#define GEOMETRY_H

int read_geometry(Cell*& Sigma, int* N);
int read_sources(Point*& Sources, int*& Q, int* N);
void clean_geometry(Cell*& Sigma);
void clean_sources(Point*& Sources, int*& Q);


#endif // GEOMETRY_H
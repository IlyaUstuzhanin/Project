#include "Classes.h"
#include "Geometry.h"
#include <iostream>
#include<stdio.h>

int main() {

	Cell ** Sigma=NULL;
	if(read_geometry(Sigma)) {
		return 1;
	}
	std::cout << Sigma[0][0].A.x;

	//read sources
	//find b
	//find A (integrator)
	//use test_blas_lapack to solve and find g
	//find c~ (integrator)
	//fing c0
	//fing c

	clean_geometry(Sigma);

	return 0;
}
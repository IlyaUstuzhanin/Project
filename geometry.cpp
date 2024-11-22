#include "Classes.h"
#include "Geometry.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include<array>

using namespace std;

int read_geometry(Cell*& Sigma, int* N) {
    std::ifstream file("East.dat");
    if (!file.is_open()) {
        std::cout << "ErrorQ" << std::endl;
        return 1;
    }
    *N = 0;
    int Quadr, numLines;
    file >> Quadr;
    Cell ** temp = new Cell*[Quadr];
    int* Nt = new int[Quadr];
    for (int i = 0; i < Quadr; i++) {
        file >> numLines;
        *N = *N + numLines;
        Nt[i] = numLines;
        temp[i] = new Cell[numLines];
        for (int j = 0; j < numLines; j++) {
            file >> temp[i][j].A.x >> temp[i][j].A.y >> temp[i][j].A.z;
            file >> temp[i][j].B.x >> temp[i][j].B.y >> temp[i][j].B.z;
            file >> temp[i][j].C.x >> temp[i][j].C.y >> temp[i][j].C.z;
            file >> temp[i][j].D.x >> temp[i][j].D.y >> temp[i][j].D.z;
            temp[i][j].collocPoint();
            temp[i][j].normal();
        }
    }
    file.close();

    Sigma = new Cell[*N];
    int Ntemp = 0;
    for (int i = 0; i < Quadr; i++) {
        for (int j = 0; j < Nt[i]; j++) {
            Sigma[Ntemp + j] = temp[i][j];
        }
        Ntemp = Ntemp + Nt[i];
    }
    delete[] temp;
    delete[] Nt;

    return 0;
}

int read_sources(Point*& Sources, int*& Q, int *N) {
    std::ifstream file("east_src.txt");
    if (!file.is_open()) {
        std::cout << "ErrorQ" << std::endl;
        return 1;
    }

    file >> *N;
    Sources = new Point[*N];
    Q = new int[*N];

    for (int i = 0; i < *N; i++) {
        file >> Sources[i].x >> Sources[i].y >> Sources[i].z;
        file >> Q[i];
    }

    return 0;
};

void clean_geometry(Cell*& Sigma) {
    delete[] Sigma;
};

void clean_sources(Point *& Sources, int*& Q) {
    delete[] Sources;
    delete[] Q;
};

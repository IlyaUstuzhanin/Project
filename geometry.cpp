#include "Classes.h"
#include "Geometry.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include<array>

using namespace std;

int read_geometry(Cell**& Sigma) {
    std::ifstream file("East.dat");
    if (!file.is_open()) {
        std::cout << "ErrorQ" << std::endl;
        return 1;
    }
    int N = 0;
    int Quadr, numLines;
    file >> Quadr;
    Sigma = new Cell*[Quadr];
    for (int i = 0; i < Quadr; i++) {
        file >> numLines;
        Sigma[i] = new Cell[numLines];
        for (int j = 0; j < numLines; j++) {
            file >> Sigma[i][j].A.x >> Sigma[i][j].A.y >> Sigma[i][j].A.z;
            file >> Sigma[i][j].B.x >> Sigma[i][j].B.y >> Sigma[i][j].B.z;
            file >> Sigma[i][j].C.x >> Sigma[i][j].C.y >> Sigma[i][j].C.z;
        }
    }
    file.close();
    return 0;
}


void read_sources() {};

void clean_geometry(Cell**& Sigma) {
    int j;
    for (int i = 0; i < 22; i++) {
        delete[] Sigma[i];
        j = i;
    }
    delete[] Sigma;
};
void clean_sources() {};

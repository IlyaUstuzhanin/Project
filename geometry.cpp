#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

struct Point {
    double x, y, z;
};

Point vector(Point a, Point b) 
{
    return {b.x - a.x, b.y - a.y, b.z - a.z};
}

Point product(Point a, Point b) 
{
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

double vectorlength(Point a) 
{
    return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

// Нормализация вектора
Point normalize(Point a) 
{
    double length = vectorlength(a);
    return {a.x / length, a.y / length, a.z / length};
}

// Разности координат для точки (x - y) (xi-xj)
Point pointDifference(Point a) 
{
    return {a.x - a.y};
}

int main()
 {
    std::ifstream file("East.dat");
    if (!file.is_open()) 
    {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    int Quadr, numLines;
    file >> Quadr >> numLines;

    int lineNumber = 1;
    while (!file.eof()) 
    {
        Point A, B, C, D;
        if (!(file >> A.x >> A.y >> A.z >> 
                  B.x >> B.y >> B.z >> 
                  C.x >> C.y >> C.z >> 
                  D.x >> D.y >> D.z)) 
                  {
            break;
        }

        Point AC = vector(A, C);
        Point BD = vector(B, D);
        Point cross = product(AC, BD);
        Point normal = normalize(cross);

        Point diffA = pointDifference(A);
        Point diffB = pointDifference(B);
        Point diffC = pointDifference(C);
        Point diffD = pointDifference(D);

        std::cout << "Строка " << lineNumber++ << ":" << std::endl;
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "  A: x=" << A.x << ", y=" << A.y << ", z=" << A.z << std::endl;
        std::cout << "  Разности A: dx=" << diffA.x << ", dy=" << diffA.y << ", dz=" << diffA.z << std::endl;

        std::cout << "  B: x=" << B.x << ", y=" << B.y << ", z=" << B.z << std::endl;
        

        std::cout << "  C: x=" << C.x << ", y=" << C.y << ", z=" << C.z << std::endl;
        

        std::cout << "  D: x=" << D.x << ", y=" << D.y << ", z=" << D.z << std::endl;
        
        std::cout << "  Вектор нормали: x=" << normal.x 
                  << ", y=" << normal.y 
                  << ", z=" << normal.z << std::endl;
    }

    file.close();
    return 0;
}

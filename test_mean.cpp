#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.h"

using namespace std;
using namespace core_numeric;

struct Coordenadas {
    double x, y;
    Coordenadas(double x=0, double y=0) : x(x), y(y) {}
    Coordenadas operator+(const Coordenadas& o) const { return {x+o.x, y+o.y}; }
    Coordenadas operator/(size_t n) const { return {x/n, y/n}; }
};

int main() {
    vector<int> v1 = {1, 2, 3};
    cout << "Mean int: " << mean(v1) << endl;

    vector<Coordenadas> v2 = {Coordenadas(1,2), Coordenadas(3,4)};
    auto res = mean(v2);
    cout << "Mean Coordenadas: " << res.x << ", " << res.y << endl;

    // NO COMPILA
    /*
    vector<string> v3 = {"a", "b"};
    auto err = mean(v3); 
    // EXPLICACIÓN: Falla el concept 'Divisible' porque string no puede dividirse entre size_t.
    */
    return 0;
}
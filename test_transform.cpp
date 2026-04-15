#include <iostream>
#include <vector>
#include "core_numeric.h"

using namespace std;
using namespace core_numeric;

int main() {
    vector<int> v = {1, 2, 3, 4};
    // Suma de cuadrados
    auto res = transform_reduce(v, [](int x) { return x * x; });
    cout << "Transform Reduce: " << res << endl;

    // NO COMPILA
    /*
    auto err = transform_reduce(v, [](int x) { return "no_sumable"; });
    // EXPLICACIÓN: El resultado de la lambda (string) no cumple 'Addable' para el reduce final.
    */
    return 0;
}
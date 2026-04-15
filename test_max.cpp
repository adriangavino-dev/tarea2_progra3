#include <iostream>
#include <vector>
#include "core_numeric.h"

using namespace std;
using namespace core_numeric;

struct Esfera {
    double radio;
    bool operator>(const Esfera& o) const { return radio > o.radio; }
};

int main() {
    // COMPILA
    vector<double> d = {1.5, 9.2, 4.0};
    cout << "Max: " << max(d) << endl;

    // NO COMPILA
    /*
    struct SinComparar { int v; };
    vector<SinComparar> v_fail = {{1}, {2}};
    auto err = max(v_fail);
    // EXPLICACIÓN: Falla el concept 'Comparable' porque la struct no tiene operator>.
    */
    return 0;
}
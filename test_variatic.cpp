#include <iostream>
#include "core_numeric.h"

using namespace std;
using namespace core_numeric;

int main() {
    // COMPILA
    cout << "Sum Variadic: " << sum_variadic(1, 2, 10, 5) << endl;
    cout << "Max Variadic: " << max_variadic(1.5, 10.2, 3.1) << endl;

    // NO COMPILA
    /*
    auto err = sum_variadic(10, "error");
    // EXPLICACIÓN: Falla el concept 'Addable' en la expansión del fold expression 
    // porque no se puede sumar un entero con un puntero a char de forma genérica.
    */
    return 0;
}
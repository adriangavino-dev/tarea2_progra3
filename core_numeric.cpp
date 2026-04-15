#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.h"

using namespace std;
using namespace core_numeric;


struct Coordenadas {
    double x, y;
    Coordenadas(double x = 0, double y = 0) : x(x), y(y) {}

    Coordenadas operator+(const Coordenadas& other) const {
        return Coordenadas(x + other.x, y + other.y);
    }

    Coordenadas operator/(size_t n) const {
        return Coordenadas(x / n, y / n);
    }

    bool operator>(const Coordenadas& other) const {
        return (x + y) > (other.x + other.y);
    }
};

int main() {
    // ======================
    // 1. CASOS QUE COMPILAN
    // ======================

    vector<int> v1 = {10, 20, 30};
    cout << "--- Pruebas con int ---" << endl;
    cout << "Suma: " << sum(v1) << endl;
    cout << "Media (double): " << mean(v1) << endl;

    vector<Coordenadas> v2 = { Coordenadas(1, 2), Coordenadas(3, 4) };
    Coordenadas m = mean(v2);
    cout << "\n--- Pruebas con Objetos ---" << endl;
    cout << "Media Coordenadas: (" << m.x << ", " << m.y << ")" << endl;

    auto s_var = sum_variadic(1, 2, 3, 4, 5);
    auto m_var = mean_variadic(10.5, 20.5);
    cout << "\n--- Pruebas Variadic ---" << endl;
    cout << "Sum Variadic: " << s_var << endl;
    cout << "Mean Variadic: " << m_var << endl;

    vector<double> v3 = {1.0, 2.0, 3.0};
    auto res = transform_reduce(v3, [](double x) { return x * x; });
    cout << "\n--- Pruebas Transform Reduce ---" << endl;
    cout << "Suma de cuadrados: " << res << endl;


    // =========================
    // 2. CASOS QUE NO COMPILAN
    // =========================

    /* EJEMPLO A: Tipo que no soporta suma
    struct Persona { string nombre; };
    vector<Persona> v_fail;
    auto fail1 = sum(v_fail);

    EXPLICACIÓN: Este código no compila porque la estructura 'Persona'
    no satisface el concept 'Addable' y el algoritmo 'sum' requiere
    que el tipo de dato tenga definido el operator+.
    */

    /* EJEMPLO B: Variadic con tipos incompatibles
    auto fail2 = sum_variadic(10, "Hola");

    EXPLICACIÓN: La fold expression (... + args) fallará en tiempo de
    compilación porque no existe una operación de suma válida entre
    un entero y un puntero de caracteres.
    */

    /* EJEMPLO C: Max con tipos no comparables
    struct SinOrden { int id; };
    vector<SinOrden> v_fail2;
    auto fail3 = max(v_fail2);

    EXPLICACIÓN: No compila porque 'SinOrden' no satisface el concept
    'Comparable' y el algoritmo 'max' necesita el operator> para
    evaluar cual elemento es mayor.
    */

    return 0;
}
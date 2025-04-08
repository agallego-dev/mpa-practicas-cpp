#include <iostream>
using namespace std;

// Función calcular1 recursiva
float calcular1(float x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return x * calcular1(x, n - 1);
    float r = calcular1(x, n / 2);
    return r * r;
}

// Función calcular1 iterativa
float calcular1_iterativo(float x, int n) {
    if (n < 0) {
        cout << "Error" << endl;
        return -1; // Retorno de error
    }
    float resultado = 1;
    while (n > 0) {
        if (n % 2 == 1) resultado *= x;
        x *= x;
        n /= 2;
    }
    return resultado;
}

int main() {
    float x;
    int n;
    cout << "Introduce un valor para x: ";
    cin >> x;
    cout << "Introduce un valor para n: ";
    cin >> n;

    if (n < 0) {
        cout << "Error" << endl;
    } else {
        cout << "Recursivo: " << calcular1(x, n) << endl;
        cout << "Iterativo: " << calcular1_iterativo(x, n) << endl;
    }
    system("pause");
    return 0;
}

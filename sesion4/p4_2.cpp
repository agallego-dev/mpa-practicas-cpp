#include <iostream>
#include <stack>
using namespace std;

// Función calcular2 recursiva
int calcular2(int x, int y) {
    if (x <= 4) return x + y;
    return calcular2(x - 4, y / 3) + x * y;
}

// Función calcular2 iterativa
int calcular2_iterativo(int x, int y) {
    stack<pair<int, int>> pila;
    int resultado = 0;
    pila.push({x, y});
    while (!pila.empty()) {
        pair<int, int> topElement = pila.top();
        pila.pop();
        int a = topElement.first;
        int b = topElement.second;

        if (a <= 4) {
            resultado += a + b;
        } else {
            pila.push({a - 4, b / 3});
            resultado += a * b;
        }
    }
    return resultado;
}

int main() {
    int x, y;
    cout << "Introduce valores para x: ";
    cin >> x;
    cout << "Introduce valores para y: ";
    cin >> y;

    cout << "Recursivo: " << calcular2(x, y) << endl;
    cout << "Iterativo: " << calcular2_iterativo(x, y) << endl;

    system("pause");
    return 0;
    
}

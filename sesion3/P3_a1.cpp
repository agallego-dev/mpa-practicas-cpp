#include <iostream>
using namespace std;

// ACTIVIDAD 1: Conversión de número a binario

// Función recursiva para imprimir la representación binaria de un número
void binario(int n) {
    if (n < 0) {
        cout << "Error: Número negativo no válido." << endl;
        return;
    }
    if (n > 1)
        binario(n / 2);
    cout << n % 2;
}

// Función recursiva con traza para imprimir la representación binaria de un número
void binario_traza(int n, int nivel = 1) {
    if (n < 0) {
        cout << "Error: Número negativo no válido." << endl;
        return;
    }
    cout << nivel << ".- binario(" << n << ")" << endl;
    if (n > 1)
        binario_traza(n / 2, nivel + 1);
    cout << n % 2;
}

int main() {
    int num;
    cout << "Introduce numero natural (incluido el 0): ";
    cin >> num;
    cout << "El numero binaroi es: ";
    binario(num);
    cout << endl;
    
    cout << "\nLa traza es:" << endl;
    binario_traza(num);
    cout << endl;
    
    system("pause");
    return 0;
}



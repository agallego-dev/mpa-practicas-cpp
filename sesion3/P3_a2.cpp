#include <iostream>
using namespace std;

int contador_llamada = 1; // Contador global para numerar llamadas recursivas

// Función recursiva con traza para calcular combinaciones C(n, k)
int combinaciones_traza(int n, int k, int nivel = 1) {
    int num_llamada = contador_llamada++; // Asigna un número único a cada llamada
    cout << string(nivel - 1, ' ') << num_llamada << ".- combinaciones_traza(" << n << ", " << k << ")" << endl;

    if (k == 0 || k == n)
        return 1;
    
    return combinaciones_traza(n - 1, k - 1, nivel + 1) + combinaciones_traza(n - 1, k, nivel + 1);
}

int main() {
    int n, k;
    cout << "\nIntroduce total de elementos (n): ";
    cin >> n;
    cout << "Introduce el tamanio del grupo (k): ";
    cin >> k;
    
    cout << "El numero de grupos es: \n" << combinaciones_traza(n, k) << endl;
    system("pause");
    return 0;
}

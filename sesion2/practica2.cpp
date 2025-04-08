#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Función para pedir la semilla
int pedirSemilla() {
    int s;
    cout << "Semilla para generar aleatorios: ";
    cin >> s;
    return s;
}

// Función para pedir el tamaño del vector
int pedirTamanyoVector() {
    int n;
    cout << "Introduce tamanio del vector: ";
    cin >> n;
    return n;
}

// Función para pedir las posiciones inicial y final del vector
void pedirPosiciones(int &ini, int &fin) {
    cout << "\nPosiciones inicial y final del vector para mostrar" << endl;
    cout << "Inicial: ";
    cin >> ini;
    cout << "Final: ";
    cin >> fin;

    // Ajuste de índices 
    ini--;  
    fin--;  
}


// Muestra el contenido de un vector en el rango especificado 
void mostrarVecPosition(int *vec, int inicio, int fin) {
    for (int i = inicio /*- 1*/; i <= fin; i++) {
        cout << vec[i] << " ";  // Asegura alineación de los números
    }
    cout << endl;
}

// Algoritmo de ordenación por inserción (Insertion Sort)
void insercion(int *vec, int n) {
    int i, j, x;
    for (i = 1; i < n; i++) {
        x = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] > x) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = x;
    }
}

// Genera un vector con números aleatorios (Caso Cualquiera)
void generarCasoCualquiera(int *vec, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 100000;  
    }
}

// Genera el caso peor (vector ordenado en orden inverso desde el inicio)
void generarCasoPeor(int *vec, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = n - i;  // Genera valores decrecientes directamente
    }
}

int main() {
    int *V;
    int n, ini, fin, semilla;
    clock_t tinicio, tfin;
    double tiempo;
    float tiempomejor;

    semilla = pedirSemilla();
    n = pedirTamanyoVector();
    pedirPosiciones(ini, fin);

    // Reservar memoria dinámica
    V = new int[n];
    if (V == NULL) {
        cout << "Fallo al reservar memoria" << endl;
        return -1;
    }

    srand(semilla);

    // Generar valores aleatorios (Caso Cualquiera)
    generarCasoCualquiera(V, n);

    cout << "\nALGORITMO DE INSERCION" << endl;

    // Caso Cualquiera
    cout << "\nCASO CUALQUIERA" << endl;
    cout << "--------------" << endl;
    cout << "Vector a ordenar: ";
    mostrarVecPosition(V, ini, fin);
    tinicio = clock();
    insercion(V, n);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;
    cout << "Vector ordenado: ";
    mostrarVecPosition(V, ini, fin);
    cout << "Tiempo de ejecucion (ms): " << tiempo << endl;

    // Caso Mejor (ya ordenado)
    cout << "\nCASO MEJOR" << endl;
    cout << "--------------" << endl;
    cout << "Vector a ordenar: ";
    mostrarVecPosition(V, ini, fin);
    tinicio = clock();
    insercion(V, n);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;
    cout << "Vector ordenado: ";
    mostrarVecPosition(V, ini, fin);
    cout << "Tiempo de ejecucion (ms): " << tiempo << endl; //se mostrará 0 pero en realidad seria 0.00... despreciable pero existe.

    // Generar Caso Peor (vector inverso)
    generarCasoPeor(V, n);

    cout << "\nCASO PEOR" << endl;
    cout << "--------------" << endl;
    cout << "Vector a ordenar: ";
    mostrarVecPosition(V, ini, fin);
    tinicio = clock();
    insercion(V, n);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;
    cout << "Vector ordenado: ";
    mostrarVecPosition(V, ini, fin);
    cout << "Tiempo de ejecucion (ms): " << tiempo << endl;

   system("pause");

    // Liberar memoria
    delete[] V;

    return 0;
}

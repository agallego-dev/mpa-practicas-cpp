/* Alejandro Gallego Lopez */

#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

int pedirDimensionVector();
int* inElementos(int n);
void printVector(int*, int, string);
int seleccionar_pivote(int*, int, int);
void intercambiar(int*, int, int);
void quicksort_traza(int*, int, int, int&);

int n;

int main()
{
    int izq = 1;
    int der;
    int* vec;
    string vecOriginal = "original";
    string vecOrde = "ordenado";

    n = pedirDimensionVector();
    der = n;
    vec = inElementos(n);

    printVector(vec, n, vecOriginal);

    int llamada = 1;
    quicksort_traza(vec, izq, der, llamada);

    printVector(vec, n, vecOrde);

    delete[] vec;
    system("pause");
    return 0;
}

// Pide la dimensión del vector
int pedirDimensionVector() {
    int n;
    cout << "Introduce num.total elementos del vector: ";
    cin >> n;
    return (n > 0) ? n : 0;
}

// Rellenamos el vector con datos introducidos por el usuario
int* inElementos(int tamanyo) {
    int* vec = new int[tamanyo + 1];
    for (int i = 1; i <= tamanyo; i++) {
        cout << "\nIntroduce elemento " << i << ": ";
        cin >> vec[i];
    }
    cout << endl;
    return vec;
}

// Imprimimos el vector
void printVector(int* vec, int tamanyo, string nombre) {
    cout << "Vector " << nombre << ": ";
    for (int i = 1; i <= tamanyo; i++) {
        cout << vec[i];
        if (i != tamanyo) {
            cout << " ";
        }
    }
    cout << endl;
}

// Función para seleccionar el pivote como la mediana de tres valores
int seleccionar_pivote(int* vec, int izq, int der) {
    int centro = (izq + der) / 2;

    int a = vec[izq];
    int b = vec[centro];
    int c = vec[der];

    // Obtener la mediana
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return centro;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return izq;
    else
        return der;
}

// Función para intercambiar dos valores
void intercambiar(int* vec, int i, int d) {
    int aux = vec[i];
    vec[i] = vec[d];
    vec[d] = aux;
}

// Función quicksort con traza
void quicksort_traza(int* vec, int izq, int der, int& numLlamada) {
    int p = seleccionar_pivote(vec, izq, der);
    if (p > 0) {
        int pivote = vec[p];
        int i = izq;
        int d = der;

        // Mostrar traza
        cout << "Llamada " << numLlamada << ": izq=" << izq << ", der=" << der;
        cout << ", posPivote=" << p << ", valorPivote=" << pivote << endl;
        numLlamada++;

        while (i <= d) {
            while (vec[i] < pivote) i++;
            while (vec[d] > pivote) d--;
            if (i <= d) {
                intercambiar(vec, i, d);
                i++;
                d--;
            }
        }

        if (izq < d) quicksort_traza(vec, izq, d, numLlamada);
        if (i < der) quicksort_traza(vec, i, der, numLlamada);
    }
}

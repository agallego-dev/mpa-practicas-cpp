#include <iostream>

using namespace std;
//1.4
int Contar(int *V, int n, int x)
{
    int i, nveces;

    nveces=0;
    for(i=1; i<=n; i++)
    {
        if(V[i]==x)
            nveces=nveces+1;
    }
    return nveces;
}

int main()
{
    int n, x;

    cout << "Introduce valor a buscar (x): ";
    cin >> x;

    cout << "Introduce n.elementos del vector (n): ";
    cin >> n;

    //1.2 GENERAR 3 VECTORES

    int *Vpeor, *Vmejor, *Vcualquiera;
    Vpeor= new int [n+1];
    Vmejor= new int [n+1];
    Vcualquiera= new int [n+1];

    if(Vmejor == NULL || Vpeor == NULL || Vcualquiera == NULL)
    {
        cout << "Error al reservar memoria, Reviselo" <<endl;
        return 0;
    }

    //1.3
    int i;
    int resultado;

    cout << "\nVector peor: " <<endl;

    for(i=1; i<=n; i++)
        {
        Vpeor[i] = x;
        }
        for(i=1; i<=n; i++)
        {
            cout << Vpeor[i] <<' ';
        }
    //1.4
    resultado = Contar(Vpeor,n,x);
    cout << endl;

    cout << "Vector mejor: " <<endl;
    for(i=1; i<=n; i++)
        {
            Vmejor[i] = x+i;
        }
        for(i=1; i<=n; i++)
        {
            cout << Vmejor[i] <<' ';
        }
    //1.4
    resultado = Contar(Vmejor,n,x);
    cout << endl;

    cout << "Vector cualquiera: " <<endl;
        for(i=1; i<=n/2; i++)
            {
                Vcualquiera[i] = x;
            }

        for(i=n/2+1; i<=n; i++)
           {
               Vcualquiera[i] = x+i;
            }
        for(i=1; i<=n; i++)
    cout << Vcualquiera[i] <<' ';
    //1.4
    resultado = Contar(Vcualquiera,n,x);
    cout << endl;

    cout << "\nCASO PEOR" << endl;
    cout << "Numero veces: " << Contar(Vpeor, n, x) << endl;
    cout << "CASO MEJOR" << endl;
    cout << "Numero veces: " << Contar(Vmejor, n, x) << endl;
    cout << "OTRO CASO" << endl;
    cout << "Numero veces: " << Contar(Vcualquiera, n, x) << endl;


    system("pause");
    return 0;
}

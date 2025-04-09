#include <iostream>
#include <string>
#include "../include/prueba.h"
//Probando esta vain 5 a 555 5585 5555 55555
using namespace std;

string imprimirPiramide(int altura){
    string piramide;
    //cout << "\n";
    //Simboliza las filas de las matriz
    for (int i = 1; i <= altura; i++)
    {
        //Mientras el valor de j sea menos que i, va a imprimir j-veces el *, simboliza columnas
        for (int j = 0; j < i; j++)
        {
            //cout << "*";
            piramide += "*";
            piramide += "\n";
        }
        //Salto de linea
        //cout << "\n";
        //piramide += "\n";
    }
    return piramide;
}

#ifndef TESTING 
int main(){
    int a, b, c;
    string resultado = "";
    
    cout << "------------------------------------------------------------\n";
    cout << "Ingrese la altura del triangulo a: ";
    cin >> a;
    cout << "Ingrese la altura del triangulo b: ";
    cin >> b;
    cout << "Ingrese la altura del triangulo c: ";
    cin >> c;
    cout << "------------------------------------------------------------\n";
    
    cout << "Imprimiendo triangulo de altura: " << a << "\n";
    resultado = imprimirPiramide(a);
    cout << resultado;

    cout << "Imprimiendo triangulo de altura: " << b << "\n";
    resultado = imprimirPiramide(b);
    cout << resultado;

    cout << "Imprimiendo triangulo de altura: " << c << "\n";
    resultado = imprimirPiramide(c);
    cout << resultado;
    return 0;
}
#endif

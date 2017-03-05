#include <iostream>
#include "Common.h"
#include "ListaAdjacencia.h"

using namespace std;

int main()
{
    ListaAdjacencia lista(10);
    lista.setAdjacencia(0,1,3.75);
    lista.setAdjacencia(2,1,1.5);
    lista.setAdjacencia(4,3,7.89);
    lista.setAdjacencia(3,3,7.89);
    lista.print();
    cout << "posicao 2,1 = " << lista.getAdjacencia(2,1) << endl;
    cout << "---------------------------" << endl;
    lista.setAdjacencia(3,3,10.89);
    lista.removeAdjacencia(0,1);
    lista.print();
    cout << "---------------------------" << endl;
    lista.removeAdjacencia(2,1);
    lista.print();
    cout << "---------------------------" << endl;
    lista.removeAdjacencia(4,3);
    lista.print();
    cout << "---------------------------" << endl;
    cout << "posicao 2,1 = " << lista.getAdjacencia(2,1) << endl;
    cout << "Hello world!" << endl;
    return 0;
}

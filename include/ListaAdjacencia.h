#ifndef LISTAADJACENCIA_H_GUARD
#define LISTAADJACENCIA_H_GUARD

#include "Common.h"
using namespace std;

class Adjacencia {
private:
    long long int destino;
    float peso;
public:
    Adjacencia(long long int,float);
    long long int getDestino() {return destino;}
    float getPeso() {return peso;}
    void setDestino(long long int destino) {this->destino = destino;}
    void setPeso(float peso) {this->peso = peso;}

};

class ListaAdjacencia
{

private:
  vector<vector<Adjacencia> > lista;
  long long int  numeroVertices;

  vector<Adjacencia>::iterator buscaIteradorAdjacencia(long long int,long long int);

public:
    ListaAdjacencia(long long int);
    ~ListaAdjacencia();
    void setAdjacencia(long long int ,long long int ,float);
    float getAdjacencia(long long int ,long long int );
    int removeAdjacencia(long long int,long long int);

    void print();

//  void detectaValorForaDosLimites(long long int ,long long int );
//  void vizinhosSaidaDeX(long long int ,stack<long long int >&);
//  void vizinhosEntradaDeX(long long int ,stack<long long int >&);
//  long long int  grauSaida(long long int );
//  long long int  grauEntrada(long long int );
//  bool temVizinhosSaida(long long int );
//  long long int  vizinhoSaidaQualquerdeX(long long int  x);
};

#endif

//TODO Adicionar peso nas arestas
//TODO Grafo não orientado

#include "ListaAdjacencia.h"

Adjacencia::Adjacencia(long long int destino, float peso) {
    this->setDestino(destino);
    this->setPeso(peso);
}

//Alocar a lista principal e as listas auxiliares de acordo com o número de vértices
//OK
ListaAdjacencia::ListaAdjacencia(long long int numeroVertices)
{
  this->numeroVertices = numeroVertices;
   for (long long int i = 0; i < numeroVertices; i++) {
     vector<Adjacencia> *temp = new vector<Adjacencia>;
     lista.push_back(*temp);
   }
}

//Limpar todas as listas auxiliares e as lista principal
//OK
ListaAdjacencia::~ListaAdjacencia()
{
  for (long long int i = 0; i < numeroVertices; i++) {
    lista[i].clear();
  }
  lista.clear();
}

//recebe dois vertices e retorna a o iterador na adjacência deles na lista do primeiro vértice, caso exista
vector<Adjacencia>::iterator ListaAdjacencia::buscaIteradorAdjacencia(long long int vertice1, long long int vertice2)
{
  vector<Adjacencia>::iterator i = lista[vertice1].begin();
  for ( ; !(lista[vertice1].empty()) && i != lista[vertice1].end(); ++i)
  {
    if (i->getDestino() == vertice2)
      break;
  }
  return i;
}

    //recebe os vértices e o peso da aresta cria/modifica a adjacência na lista de cada um dos vértices
void ListaAdjacencia::setAdjacencia(long long int vertice1, long long int vertice2, float peso)
{
    vector<Adjacencia>::iterator i1 = buscaIteradorAdjacencia(vertice1,vertice2);
    if (i1 == lista[vertice1].end()) //se a adjacência não existe, criar
    {
        Adjacencia adj1(vertice2,peso);
        Adjacencia adj2(vertice1,peso);
        lista[vertice1].push_back(adj1);
        lista[vertice2].push_back(adj2);
    }
    else //se já existe, atualizar o peso das adjacências
    {
        vector<Adjacencia>::iterator i2 = buscaIteradorAdjacencia(vertice2,vertice1);
        i1->setPeso(peso);
        i2->setPeso(peso);
    }
}

//recebe dois vértices e retorna o valor do peso da aresta entre eles. caso a aresta não exista, retorna 0
float ListaAdjacencia::getAdjacencia(long long int vertice1, long long int vertice2)
{
    vector<Adjacencia>::iterator i = buscaIteradorAdjacencia(vertice1,vertice2);
    if (i != lista[vertice1].end())
        return i->getPeso();
    return 0;
}

//recebe dois vertices e, caso exista, remove a adjacência na lista dos dois vértices e retorna 1.
//caso não exista, retorna 0
int ListaAdjacencia::removeAdjacencia(long long int vertice1, long long int vertice2)
{
    vector<Adjacencia>::iterator i1 = buscaIteradorAdjacencia(vertice1,vertice2);
    if (i1 != lista[vertice1].end())
    {
        vector<Adjacencia>::iterator i2 = buscaIteradorAdjacencia(vertice2,vertice1);
        lista[vertice1].erase(i1);
        lista[vertice2].erase(i2);
        return 1;
    }
    else
    {
        return 0;
    }
}

//imprime o grafo como matriz
void ListaAdjacencia::print ()
{
  for (long long int i = 0; i < numeroVertices; i++)
  {
    for (long long int j = 0; j < numeroVertices; j++)
    {
      printf("%.2f ", getAdjacencia(i,j));
    }
    printf("\n");
  }
}

#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include <iostream>
#include <vector>


using namespace std;
class Grafo{
private:
 int V; // número de vértices
 vector<int> *Arestas; // ponteiro para um array contendo as listas de adjacências

public:
 Grafo(int V); // construtor
 void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
 void removeAresta(int v1, int v2); //remove aresta dos vertices
 int obterGrau(int v); //retorna grau de vertice
 friend class AlgoritmoFleury;
};

#endif

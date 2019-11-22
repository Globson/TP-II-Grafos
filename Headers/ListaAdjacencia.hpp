#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include <iostream>
#include <vector>
#include <algorithm> // função find
#include <stack> // pilha para usar na DFS

using namespace std;
class Grafo{
private:
 int V; // número de vértices
 vector<int> *adj; // ponteiro para um array contendo as listas de adjacências

public:
 Grafo(int V); // construtor
 void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
 void removeAresta(int v1, int v2);
 // faz uma DFS a partir de um vértice
 void dfs(int v);
 int obterGrau(int v);
 friend class AlgoritmoFleury;
};

#endif

#ifndef FUNCS_HPP
#define FUNCS_HPP
// Grafos - Lista de adjacência

#include <iostream>
#include <list>
#include <algorithm> // função find

using namespace std;

class Grafo
{
	int V; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo

	// obtém o grau de saída de um dado vértice
	// grau de saída é o número de arcos que saem de "v"
	int obterGrauDeSaida(int v);
  int obterGrau(int v);
	bool existeVizinho(int v1, int v2); // verifica se v2 é vizinho de v1
};


#endif

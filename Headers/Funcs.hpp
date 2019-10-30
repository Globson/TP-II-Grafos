#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <iostream>
#include <ctime>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;
void inicializaMatrizAleatoria(int Matriz[][3]);
void inicializaMatrizResolvida(int MatrizR[][3]);

class Grafo{
  int V; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
  void AcrescentaVertice(int NovoV);
  void getAdjacencias();
	// faz uma DFS a partir de um vértice
	void dfs(int v);
};
#endif

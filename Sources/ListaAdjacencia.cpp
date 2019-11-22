#include "../Headers/ListaAdjacencia.hpp"

Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adj = new vector<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
  adj[v2].push_back(v1);
}

void Grafo::removeAresta(int v1, int v2){
	for(unsigned int i=0;i<adj[v1].size();i++){
		if(adj[v1].at(i)==v2){
			adj[v1].erase(adj[v1].begin()+i);
			break;
		}
	}
	for(unsigned int j=0;j<adj[v2].size();j++){
		if(adj[v2].at(j)==v1){
			adj[v2].erase(adj[v2].begin()+j);
			break;
		}
	}
}

int Grafo::obterGrau(int v){
  return adj[v].size();
}

#include "../Headers/ListaAdjacencia.hpp"

Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	Arestas = new vector<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	Arestas[v1].push_back(v2);
  Arestas[v2].push_back(v1);
}

void Grafo::removeAresta(int v1, int v2){
	for(unsigned int i=0;i<Arestas[v1].size();i++){
		if(Arestas[v1].at(i)==v2){
			Arestas[v1].erase(Arestas[v1].begin()+i);
			break;
		}
	}
	for(unsigned int j=0;j<Arestas[v2].size();j++){
		if(Arestas[v2].at(j)==v1){
			Arestas[v2].erase(Arestas[v2].begin()+j);
			break;
		}
	}
}

int Grafo::obterGrau(int v){
  return Arestas[v].size();
}

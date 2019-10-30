#include "../Headers/Funcs.hpp"
Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

int Grafo::obterGrauDeSaida(int v)
{
	// basta retornar o tamanho da lista que é a quantidade de vizinhos
	return adj[v].size();
}

bool Grafo::existeVizinho(int v1, int v2)
{
	if((find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()) || (find(adj[v2].begin(), adj[v2].end(), v1) != adj[v2].end()))
		return true;
	return false;
}

int Grafo::obterGrau(int v){
  int grau=0;
  for(int i=0;i<V;i++){
      if(find(adj[i].begin(), adj[i].end(),v) != adj[i].end()){
        grau++;
        //cout<<i<<endl;
      }
  }
  cout<<"Valor do grau dele: "<<adj[v].size()<<endl;
  cout<<"Valor do grau na lista de outros: "<<grau<<endl;
  return grau+adj[v].size();
}

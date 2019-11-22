// Grafos - DFS (busca em profundidade)
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
void Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[V]; // vetor de visitados

	// marca todos como não visitados
	for(int i = 0; i < V; i++)
		visitados[i] = false;

	while(true)
	{
		if(!visitados[v])
		{
			cout << "Visitando vertice " << v << " ...\n";
			visitados[v] = true; // marca como visitado
			pilha.push(v); // insere "v" na pilha
		}

		bool achou = false;
		vector<int>::iterator it;

		// busca por um vizinho não visitado
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				achou = true;
				break;
			}
		}

		if(achou)
			v = *it; // atualiza o "v"
		else
		{
			// se todos os vizinhos estão visitados ou não existem vizinhos
			// remove da pilha
			pilha.pop();
			// se a pilha ficar vazia, então terminou a busca
			if(pilha.empty())
				break;
			// se chegou aqui, é porque pode pegar elemento do topo
			v = pilha.top();
		}
	}
}
int Grafo::obterGrau(int v){
  return adj[v].size();
}


/*int main()
{
	int V = 8;

	Grafo grafo(V);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);

	grafo.dfs(0);

	return 0;
}
*/

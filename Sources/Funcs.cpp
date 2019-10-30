#include "../Headers/Funcs.hpp"


void inicializaMatrizAleatoria(int Matriz[][3]){
  vector<int> Vetor;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      bool Presente;
      int a;
      do{
        Presente = false;
        a = rand()%9;
        for(unsigned int k=0;k<Vetor.size();k++){
          if(a == Vetor.at(k)){
            Presente = true;
          }
        }
      }while(Presente);
      Matriz[i][j] = a;
      Vetor.push_back(a);
    }
}
void inicializaMatrizResolvida(int MatrizR[][3]){
  int k=0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      MatrizR[i][j]=k;
      k++;
    }
}

//metodos de classe grafo
Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as lista, sendo um vetor de listas de V posicoes
}

void Grafo::AcrescentaVertice(int NovoV){
  list<int> AuxList[V];
  for(int i = 0; i<V; i++){
    AuxList[i]=adj[i];
  }
  adj = new list<int>[NovoV];
  for(int i = 0;i<V; i++){
    adj[i]=AuxList[i];
  }
  this->V = NovoV;
}

void Grafo::getAdjacencias(){
  cout<< this->V <<endl;
  list<int> ListAux[V];
  for(int j =0;j<V;j++){
    ListAux[j] = adj[j];
  }
  for(int i = 0;i<V;i++){
    cout<<"Vertice "<<i<<" é adjacente a: ";
    while (!ListAux[i].empty()) {
      cout << ListAux[i].front()<<", ";
      ListAux[i].pop_front();
    }
    cout<<endl;
  }
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
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
		list<int>::iterator it;

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

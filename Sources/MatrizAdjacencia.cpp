#include "../Headers/MatrizAdjacencia.hpp"

void Grafo::inicializar() {
    for (int i = 0; i <= this->n; i++){
        for (int j = 0; j <= this->n; j++){
            MatrizAdjacencia[i][j] = 0;
            QuantDeArestas[i][j] = 0;
        }
    }
}

void Grafo::inserirAresta(int u, int v, int w){
    MatrizAdjacencia[u][v] = w;
    MatrizAdjacencia[v][u] = w;
    QuantDeArestas[u][v] += 1;
    QuantDeArestas[v][u] += 1;
    m++;
}

void Grafo::mostrar() {
    int k = 3;
    cout << "   ";
    for (int j = 1; j <= this->n; j++){
        cout << setw(k) << j;
    }
    cout << endl;
    for (int j = 1; j <= (this->n*k+3); j++){
        cout << "-";
    }
    cout << endl;
    for (int i = 1; i <= this->n; i++){
        cout << setw(1) << i;
        cout << " |";
        for (int j = 1; j <= this->n; j++){
            cout << setw(k) << MatrizAdjacencia[i][j];
        }
        cout << endl;
    }
}
int Grafo::retornaGrau(int v){
  int cont=0;
  for(int j=1;j<=n;j++){
    cont+=QuantDeArestas[v][j];
  }
  return cont;
}

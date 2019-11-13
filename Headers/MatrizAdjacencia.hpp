#ifndef MATRIZADJACENCIA_HPP
#define MATRIZADJACENCIA_HPP

#include <iostream>
#include <iomanip>
#define NUMVERTICES 100
using namespace std;


class Grafo {
private:
    int MatrizAdjacencia[NUMVERTICES+1][NUMVERTICES+1];
    int QuantDeArestas[NUMVERTICES+1][NUMVERTICES+1];
    int n, m;

public:
    Grafo(int n){
        this-> n = n;
        this->m = 0;
        inicializar();
    }

    void inicializar();
    void inserirAresta(int u, int v, int w); // u = vertice 1, v= vertice 2, w = peso da aresta
    void mostrar();
    int retornaGrau(int v);

};


#endif //GRAFOMATRIZ_GRAFO_H

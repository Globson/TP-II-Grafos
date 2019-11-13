#ifndef GRAFOMATRIZ_GRAFO_H
#define GRAFOMATRIZ_GRAFO_H

#include <iostream>
#include <iomanip>
#define NUMVERTICES 100
using namespace std;


class Grafo {
private:
    int mat[NUMVERTICES][NUMVERTICES];
    int n, m;

public:
    Grafo(int n){
        this-> n = n;
        this->m = 0;
        inicializar();
    }

    void inicializar();
    void inserirAresta(int u, int v, int w);
    void mostrar();

};


#endif //GRAFOMATRIZ_GRAFO_H

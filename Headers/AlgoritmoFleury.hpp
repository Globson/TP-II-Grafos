#ifndef ALGORITMOFLEURY_HPP
#define ALGORITMOFLEURY_HPP
#include "ListaAdjacencia.hpp"
class AlgoritmoFleury{
private:
  Grafo *GrafoInterno;
  void DFS(int x,bool Visitados[]);
  int QuantVerticesVisitados(bool Visitados[]);
  bool ArestaValida(int i, int j);
  void ImprimePasseioEuleriano(int VerticeInicio);
public:
  void VerificaEuleriano(Grafo *Grafo);
  bool VerificaConexo();
  void EscolheArestaImprime();


};
#endif

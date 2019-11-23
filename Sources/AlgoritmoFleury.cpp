#include "../Headers/AlgoritmoFleury.hpp"

void AlgoritmoFleury::DFS(int x,bool Visitados[]){
  Visitados[x] = true;
  vector<int>::iterator it;
  // busca por um vizinho não visitado
  for(it = GrafoInterno->adj[x].begin(); it != GrafoInterno->adj[x].end(); it++)
  {
    if(!Visitados[*it])
    {
      DFS(*it,Visitados);
    }
  }
}
void AlgoritmoFleury::VerificaEuleriano(Grafo *Grafo){
  this->GrafoInterno = Grafo;
  if(!VerificaConexo()){
    cout<<"   -->Grafo nao euleriano<--"<<endl<<endl;
    return;
  }
  int aux=0;
  for(int i=0;i<GrafoInterno->V;i++){
    if(GrafoInterno->obterGrau(i)%2 == 1){
      aux++;
    }
  }
  if(aux>2){
    cout<<"   -->Grafo nao euleriano<--"<<endl<<endl;
    return;
  }

  if(aux==2){
    cout<<"   -->Grafo semi-euleriano<--"<<endl<<endl;
    cout<<"Impressao da trilha euleriana:"<<endl;
    EscolheArestaImprime();
    return;
  }
  else{
    cout<<"   -->Grafo euleriano<--"<<endl<<endl;
    cout<<"Impressao do ciclo euleriano:"<<endl;
    EscolheArestaImprime();
    return;
  }

}
bool AlgoritmoFleury::VerificaConexo(){
  bool Visitados[GrafoInterno->V];
  for(int i=0;i<GrafoInterno->V;i++){
    Visitados[i]=false;
  }
  int j;
  for(j=0;j<GrafoInterno->V;j++){
    if(!GrafoInterno->adj[j].empty()){
      break;
    }
  }
  if(j==GrafoInterno->V){
    return true;
  }
  DFS(j,Visitados);
  for(int i=0;i<GrafoInterno->V;i++){
      if ((!Visitados[i]) && GrafoInterno->adj[i].size() > 0){
            return false;
      }
  }
  return true;
}
void AlgoritmoFleury::EscolheArestaImprime(){
  int VerticeInicial = 0;
  for(int i=0;i<GrafoInterno->V;i++){
    if(GrafoInterno->adj[i].size()%2==1){
      VerticeInicial = i;
      break;
    }
  }
  ImprimePasseioEuleriano(VerticeInicial);
}
int AlgoritmoFleury::QuantVerticesVisitados(bool Visitados[]){
  int aux=0;
  for(int i=0;i<GrafoInterno->V;i++){
    if(Visitados[i]){
      aux++;
    }
  }
  return aux;
}

bool AlgoritmoFleury::ArestaValida(int i, int j){  //Verifica se é ponte;
  if(GrafoInterno->adj[i].size()==1){
    return true;
  }

  bool Visitados1[GrafoInterno->V];
  bool Visitados2[GrafoInterno->V];
  for(int i=0;i<GrafoInterno->V;i++){
    Visitados1[i] = false;
    Visitados2[i] = false;
  }
  DFS(i,Visitados1);
  GrafoInterno->removeAresta(i,j);
  DFS(i,Visitados2);
  GrafoInterno->adicionarAresta(i,j);
  return QuantVerticesVisitados(Visitados2) >= QuantVerticesVisitados(Visitados1);
}

void AlgoritmoFleury::ImprimePasseioEuleriano(int VerticeInicio){
  for(unsigned int i=0;i<GrafoInterno->adj[VerticeInicio].size();i++){
      int x = GrafoInterno->adj[VerticeInicio].at(i);
      if(ArestaValida(VerticeInicio,x)){
        cout<<"\t("<<(VerticeInicio+1)<<")<==>("<<(x+1)<<")"<<endl;
        GrafoInterno->removeAresta(VerticeInicio, x);
        ImprimePasseioEuleriano(x);
      }
  }
}

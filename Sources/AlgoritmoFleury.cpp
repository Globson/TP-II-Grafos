#include "../Headers/AlgoritmoFleury.hpp"

void AlgoritmoFleury::DFS(int x,bool Visitados[]){ // busca por um vizinho não visitado
  Visitados[x] = true;  //marca todos os vertices visitados
  vector<int>::iterator it;
  for(it = GrafoInterno->Arestas[x].begin(); it != GrafoInterno->Arestas[x].end(); it++){
    if(!Visitados[*it]){
      DFS(*it,Visitados);
    }
  }
}

void AlgoritmoFleury::VerificaEuleriano(Grafo *Grafo){ // Função verifica se grafo é euleriano
  this->GrafoInterno = Grafo;
  if(!VerificaConexo()){ // Verifica se todas as arestas sao acessiveis
    cout<<"   -->Grafo nao euleriano<--"<<endl<<endl;
    return;
  }
  int aux=0;
  for(int i=0;i<GrafoInterno->V;i++){
    if(GrafoInterno->obterGrau(i)%2 == 1){
      aux++;   //Quantidade de vertices de grau impar
    }
  }
  if(aux>2){ //se maior que 2 grafo nao pode ser euleriano
    cout<<"   -->Grafo nao euleriano<--"<<endl<<endl;
    return;
  }

  if(aux==2){ // se exatamente igual a 2 grafo é semi-euleriano
    cout<<"   -->Grafo semi-euleriano<--"<<endl<<endl;
    cout<<"Impressao da trilha euleriana:"<<endl;
    EscolheArestaImprime();
    return;
  }
  else{ //caso seja menor  que 2, o grafo é euleriano
    cout<<"   -->Grafo euleriano<--"<<endl<<endl;
    cout<<"Impressao do ciclo euleriano:"<<endl;
    EscolheArestaImprime();
    return;
  }

}
bool AlgoritmoFleury::VerificaConexo(){  //Função para verificar se é possivel acessar todas as arestas apartir de um dado vertice
  bool Visitados[GrafoInterno->V];  //Vetor para marcar vertices visitados
  for(int i=0;i<GrafoInterno->V;i++){
    Visitados[i]=false;
  }
  int j;
  for(j=0;j<GrafoInterno->V;j++){
    if(!GrafoInterno->Arestas[j].empty()){
      break;  //caso alguma aresta seja encontrada no grafo, o for será interrompido
    }
  }
  if(j==GrafoInterno->V){ //Caso o for nao seja interrompido
    return false; // O grafo não possui nenhuma aresta
  }
  DFS(j,Visitados);
  for(int i=0;i<GrafoInterno->V;i++){
      if ((!Visitados[i]) && GrafoInterno->obterGrau(i) > 0){ //Se algum vertice nao for visitado e possuir alguma aresta, o grafo é disconexo.
            return false;
      }
  }
  return true;
}

void AlgoritmoFleury::EscolheArestaImprime(){ //Função para escolher uma aresta inicial e em seguida começar a impressão do ciclo ou trilha.
  int VerticeInicial = 0;
  for(int i=0;i<GrafoInterno->V;i++){
    if(GrafoInterno->obterGrau(i)%2==1){  //Prioriza começar por vertices de grau impar.
      VerticeInicial = i;
      break;
    }
  }
  ImprimePasseioEuleriano(VerticeInicial); // Chama impressao
}
int AlgoritmoFleury::QuantVerticesVisitados(bool Visitados[]){ // Função que retorna quantos vertices foram visitados.
  int aux=0;
  for(int i=0;i<GrafoInterno->V;i++){
    if(Visitados[i]){
      aux++;
    }
  }
  return aux;
}

bool AlgoritmoFleury::ArestaValida(int i, int j){  //Retorna true caso aresta não seja uma ponte, false caso seja.
  if(GrafoInterno->obterGrau(i)==1){ //Caso o grau seja 1,
    return true;
  }

  bool Visitados1[GrafoInterno->V]; //Vetores de visitados para comparações
  bool Visitados2[GrafoInterno->V];
  for(int i=0;i<GrafoInterno->V;i++){
    Visitados1[i] = false;
    Visitados2[i] = false;
  }
  DFS(i,Visitados1);
  GrafoInterno->removeAresta(i,j);
  DFS(i,Visitados2);                      //São computados os vetores de visitados um com a aresta e outro sem.
  GrafoInterno->adicionarAresta(i,j);
  return (QuantVerticesVisitados(Visitados2) >= QuantVerticesVisitados(Visitados1));  //Caso a quantidade de vertices visitados forem maiores ou igual, aresta não é uma ponte.
}

void AlgoritmoFleury::ImprimePasseioEuleriano(int VerticeInicio){  //Impressão de caminho ou ciclo euleriano
  for(int i=0;i<GrafoInterno->obterGrau(VerticeInicio);i++){
      int x = GrafoInterno->Arestas[VerticeInicio].at(i);
      if(ArestaValida(VerticeInicio,x)){
        cout<<"\t("<<(VerticeInicio+1)<<")<==>("<<(x+1)<<")"<<endl;
        GrafoInterno->removeAresta(VerticeInicio, x); //Aresta impressa é removida
        ImprimePasseioEuleriano(x); //Processo é chamado recursivamente
      }
  }
}

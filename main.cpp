#include "Headers/ListaAdjacencia.hpp"
#include "Headers/AlgoritmoFleury.hpp"
int main(int argc, char const *argv[]) {
  FILE *f;
  char NomeArquivo[20];
  int Vertices=0,valorAux1=0,valorAux2=0;
  Grafo *grafo;
  cout<<"\nDigite o nome do arquivo que deseja abrir:";    //Abrindo arquivo//
  cin>>NomeArquivo;
  f = fopen(NomeArquivo,"r");
  if(f == NULL){
    cout<<"\n\tErro!Nao foi possivel abrir arquivo!\n";}  //Caso erro de abertura, programa solicita novamente entrada//
  else{
    cout<<"\n\tArquivo aberto com sucesso!"<<endl;
    if(!feof(f)){
      fscanf(f,"%d",&Vertices);
      grafo = new Grafo(Vertices); //Vertice 0 é sempre desconsiderado
      cout<<"Quantidade de vertices: "<<Vertices<<endl;
      cout<<"Arestas: "<<endl;
      while(!feof(f)){
         fscanf(f,"%d %d ",&valorAux1,&valorAux2);
         cout<<"\t("<<valorAux1<<")====("<<valorAux2<<")"<<endl;
         grafo->adicionarAresta(valorAux1-1,valorAux2-1);
      }
    }
    fclose(f);
    AlgoritmoFleury Teste;
    cout<<endl;
    Teste.VerificaEuleriano(grafo);
  }

  return 0;
}

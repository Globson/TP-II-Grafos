#include "Headers/ListaAdjacencia.hpp"
#include "Headers/AlgoritmoFleury.hpp"
int main(int argc, char const *argv[]) {
  FILE *f;
  char NomeArquivo[20];
  int Vertices,valorAux1,valorAux2;
  Grafo *grafo;
  cout<<"\nDigite o nome do arquivo que deseja abrir:";    //Abrindo arquivo//
  cin>>NomeArquivo;
  f = fopen(NomeArquivo,"r");
  if(f == NULL){
    cout<<"\n\tErro!Nao foi possivel abrir arquivo!\n";}  //Caso erro de abertura, programa solicita novamente entrada//
  else{
    cout<<"\n\tArquivo aberto com sucesso!"<<endl;
    if(!feof(f)){
      fscanf(f,"%d ",&Vertices);
      grafo = new Grafo(Vertices);
      cout<<"Quantidade de vertices: "<<Vertices<<endl;
      cout<<"Arestas: "<<endl;
      while(!feof(f)){
         fscanf(f,"%d %d ",&valorAux1,&valorAux2);
         cout<<"\t("<<valorAux1<<")====("<<valorAux2<<")"<<endl;
         grafo->adicionarAresta(valorAux1-1,valorAux2-1); //Vertices recebem -1 para serem contabilizados da forma correta
      }
    }
    fclose(f);
    AlgoritmoFleury EulerTest;
    cout<<endl;
    EulerTest.VerificaEuleriano(grafo);
  }

  return 0;
}

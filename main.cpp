#include "Headers/MatrizAdjacencia.hpp"
int main(int argc, char const *argv[]) {
  FILE *f;
  char NomeArquivo[20]="Arquivo.txt";
  int Vertices=0,valorAux1=0,valorAux2=0;
  cout<<"\nDigite o nome do arquivo que deseja abrir:";    //Abrindo arquivo//
  //cin>>NomeArquivo;
  f = fopen(NomeArquivo,"r");
  if(f == NULL){
    cout<<"\n\tErro!Nao foi possivel abrir arquivo!\n";}  //Caso erro de abertura, programa solicita novamente entrada//
  else{
    cout<<"\n\tArquivo aberto com sucesso!"<<endl;
    if(!feof(f)){
      fscanf(f,"%d",&Vertices);
      //cout<<valorAux1<<endl;
      Grafo grafo(Vertices+1); //Vertice 0 é sempre desconsiderado
      while(!feof(f)){
        fscanf(f,"%d %d",&valorAux1,&valorAux2);
         cout<<"ValorAux1: "<<valorAux1<<endl;
         cout<<"ValorAux2: "<<valorAux2<<endl<<endl;
         grafo.inserirAresta(valorAux1,valorAux2,1);
      }
      grafo.mostrar();
      for(int i=1;i<=Vertices+1;i++){
        cout<<endl<<"O grau do vertice "<<i<<" é: "<<grafo.retornaGrau(i)<<endl;
      }

    }


  }

  return 0;
}

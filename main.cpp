#include "Headers/Funcs.hpp"
int main(int argc, char const *argv[]) {
  /*// criando um grafo de 4 vértices
	Grafo grafo(4);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 3);
	grafo.adicionarAresta(1, 2);
	grafo.adicionarAresta(3, 1);
	grafo.adicionarAresta(3, 2);

	// mostrando os graus de saída
	cout << "Grau de saida do vertice 1: " << grafo.obterGrauDeSaida(1);
	cout << "\nGrau de saida do vertice 3: " << grafo.obterGrauDeSaida(3);

	// verifica se existe vizinhos
	if(grafo.existeVizinho(0, 1))
		cout << "\n\n1 eh vizinho de 0\n";
	else
		cout << "\n\n1 NAO eh vizinho de 0\n";

	if(grafo.existeVizinho(0, 2))
		cout << "2 eh vizinho de 0\n";
	else
		cout << "2 NAO eh vizinho de 0\n";
*/
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
        grafo.adicionarAresta(valorAux1,valorAux2);
      }
      while(true){
        int valor;
        cout<<"Entre com o vertice a verificar grau:";
        cin>>valor;
        cout<<grafo.obterGrau(valor)<<endl;
      }

    }


  }

  return 0;
}

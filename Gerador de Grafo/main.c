#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  FILE *f;
  int Vertices,Semi;
  char Nome[20];
  printf("Entre com o nome do arquivo de saida ser criado: ");
  scanf("%s",Nome);
  f = fopen(Nome,"w");
  printf("Entre com a quantidade de vertices(impares para eulerianos,pares para nao-eulerianos):");
  scanf("%d",&Vertices);
  printf("\nEscolha:\n\t1 - Euleriano\n\t2 - Semi-Euleriano\n");
  do{
    printf("Entre:");
    scanf("%d",&Semi);
    if(Semi!=1 && Semi!=2){
      printf("Erro! Opcao invalida!\n");
    }
  }while(Semi!=1 && Semi!=2);
  fprintf(f,"%d\n",Vertices);
  if(Semi==1){
    for(int i=1;i<=Vertices;i++){
      for(int j=i+1;j<=Vertices;j++){
        fprintf(f,"%d %d\n",i,j);
      }
    }
  }
  else{
    for(int i=1;i<=Vertices;i++){
      for(int j=i+1;j<=Vertices;j++){
        if(i==Vertices-1 && j==Vertices){
          break;
        }
        fprintf(f,"%d %d\n",i,j);
      }
    }
  }
  printf("Arquivo gerado com sucesso!\n");
  fclose(f);
  return 0;
}

/*QUESTÃO 1 -----
Implementar programa para ler total de vendas, de um
determinado mês, dos 300 vendedores da “Matura”,
calcular a média de vendas do grupo de vendedores, e
exibir quantos vendedores apresentaram desempenho
(vendas) abaixo da média.*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int desempenho(int V[], int tamanho, float media){
 int aux = 0;
  for(int cont = 0; cont < tamanho; cont++ ){
    if(V[cont] < media){
      aux++;
    }
  }
  return aux;
}

int media(int V[], int tamanho){
  int aux = 0;
  for (int cont = 0; cont < tamanho; cont++ ){
    aux += V[cont];
  }
  return (float) aux/tamanho;
}

int main(void){

  int vendas[10], med, numAbaixo;
  for (int cont = 0; cont < 10; cont++){
    printf("Digite o numero de vendas do vendedor %d: ", cont + 1);
    scanf("%d", &vendas[cont]);
  }

  med = media(vendas, 10);
  numAbaixo = desempenho(vendas, 10, med);

  printf("\nA media de vendas dos funcionarios é de: %d \n", med);
  printf("O número de funcionarios abaixo da media eh de: %d\n ",numAbaixo);
}
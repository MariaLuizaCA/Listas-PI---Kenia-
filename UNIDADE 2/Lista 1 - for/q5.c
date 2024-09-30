/* 
ENTRADA: numero de recebimentos e numeros para o fatorial 
PROCESSAMENTO: função do fatorial
SAIDA: o fatorial de cada numero
 */

#include <stdio.h>

int fatorial(int n){
  int resultado = 1;
  for (int aux = 1; aux <= n; ++aux) {//incrementa antes
      resultado = resultado * aux;
  }
  return resultado;
}

int main(void){
  int rep;
  printf("Digite quantos numeros serao calculados: ");
  scanf("%d", &rep);
  for(int cont = 1; cont<=rep; cont++){
    int resultado ;
    int n;
    printf("Digite o numero para calcular o fatorial: ");
    scanf(" %d", &n);
    if (n==0){
      printf("1");
    }else{
      if(n<0){
        printf("O numero eh invalido.");
      } else {
        resultado = fatorial(n);
        printf("O fatorial de %d eh: %d", n, resultado);
      }
    }
  }
}
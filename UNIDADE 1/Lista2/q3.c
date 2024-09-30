/*Ler um número N (n especificado)
retornar N3(N ao cubo) (função).*/

#include <stdio.h>
#include <math.h>

float cubo(int n){
  int resultado;
  resultado = n*n*n; // função de potência 'pow(base, expoente)'
  return resultado;
}

int main(void){
  int numero;
  printf("Digite o numero a ser calculado: ");//2, 4.2
  scanf("%f", &numero);
  printf("O numero ao cubo e: %.2f", cubo(numero));//8, 74.09
}

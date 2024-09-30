/*Exibir: exibir menu: 1 –area, 2 – perímetro e 3 – diagonal
Receber: medidas de lado do quadrado(lado)
Exibir: a informação solicitada pelo usuário no menu ou uma mensagem de erro*/

#include <stdio.h>
#include <math.h>

float area(float lado, float *resultado){
  *resultado = lado*lado;
}
float perimetro(float lado, float *resultado){
  *resultado = 4*lado;
}
float diagonal(float lado, float *resultado){
  *resultado = lado*sqrt(2);
}

int main(void){
  int opcao;
  float lado, resultado;
  printf("MENU -------------\n1 - area\n2 - perimetro\n3 - diagonal\nSua opçao: ");
  scanf("%d", &opcao);
  printf("Digite a medida do lado do quadrado: ");
  scanf("%f", &lado);
  if(opcao == 1){
    area(lado, &resultado);
    printf("A area do quadrado eh: %.2f\n", resultado);
  }
  else{
    if (opcao == 2){
      perimetro(lado, &resultado);
      printf("O perimetro do quadrado eh: %.2f\n", resultado);
    }
    else{
      if(opcao == 3){
        diagonal(lado, &resultado);
        printf("A diagonal do quadrado eh: %.2f\n", resultado);
      }
      else
        printf("Opcao invalida");
    }
  }
}
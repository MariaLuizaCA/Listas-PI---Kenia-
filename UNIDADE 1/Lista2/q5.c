/* Ler o raio de um círculo (float)
Exibir em tela a área 
Área = π . Funções separadas para areaCirc e quadrado, pi como constante */

#include <stdio.h>
#include <math.h>

#define PI 3.14

float quadrado(float n){
  float resultado;
  resultado = n*n;
  return resultado;
}

float areaCirc(float raio){
  float area;
  area = PI * quadrado(raio);
  return area;
}

int main(void) {
  float r;
  printf("Digite o raio do círculo: ");
  scanf("%f",&r);//3.6
  printf("A área do círculo é: %.2f",areaCirc(r));//40.69
}
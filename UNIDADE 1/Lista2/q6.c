/*6.Ler peso em kg(float) e altura em m(float). 
Exibir o IMC da pessoa
IMC = peso / altura2(função) e quadrado (função)*/

#include <stdio.h>
#include <math.h>

float quadrado(float n){
  float resultado;
  resultado = n*n;
  return resultado;
}

float imc(float peso, float altura){
  float resultado;
  resultado = peso/quadrado(altura);
  return resultado;
}

int main(void) {
  float peso, altura;
  printf("Digite o seu peso em kg: ");
  scanf("%f", &peso);//45
  printf("Digite a sua altura em m: ");
  scanf("%f", &altura);//1,69
  printf("O seu IMC eh: %.2f", imc(peso, altura));//15.76
}
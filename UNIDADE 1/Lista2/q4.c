/*Ler uma temperatura em Celsius C  
Retornar em Fahrenheit e em Kelvin.
Fahrenheit: F = (C * 9/5) + 32; para Kelvin: K = C + 273,5.
Criar uma função para cada conversão.*/

#include <stdio.h>
#include <math.h>

float fahrenheit(int c){ //para calcular apenas a temperatura em fahrenheit
  float temp = (c * 9/5) + 32;
  return temp;
}

float kelvin(int c){ //para calcular apenas a temperatura em kelvin
    float temp = c + 273.5;
    return temp;
}

int main(void) {
  int celsius;
  printf("Digite a temperatura em Celsius: ");
  scanf("%d", &celsius);//30
  printf("A temperatura em Fahrenheit e: %.2f\n E a temperatua em Kelvin e:  %.2f ", fahrenheit(celsius), kelvin(celsius));//f=86.00 e k=303.50
}
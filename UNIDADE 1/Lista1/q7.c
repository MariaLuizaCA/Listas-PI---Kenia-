#include <stdio.h>
// QUESTÃO 7 - Converter a temperatura de Celsius para Fahrenheit. Solicite ao usuário a temperatura em Celsius e exiba o resultado em Fahrenheit. Pesquise e escreva, como comentário, a regra de conversão usada.
// fórmula: C/5 = F-32/9
int main(void) {
  float celsius;
  printf("Digite a temperatura em Celsius: ");//37
  scanf("%f", &celsius);
  printf("A temperatura em Fahrenheit eh: %.1f", (celsius*1.8)+32);//98.6
  return 0;
}
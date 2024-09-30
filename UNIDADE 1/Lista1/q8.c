#include <stdio.h>
// QUESTÃO 8 - Calcular a área de um retângulo. O usuário deve fornecer o comprimento e a largura desse.
int main(void) {
  float comprimento, largura;
  printf("Digite o comprimento: "); // 30
  scanf("%f", &comprimento);
  printf("Diggite a largura: "); // 4,5
  scanf("%f", &largura);
  printf("A area do retangulo eh: %.2f", comprimento * largura); // 135
  return 0;
}

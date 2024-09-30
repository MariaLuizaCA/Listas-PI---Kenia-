#include <stdio.h>

//QUESTÃO 2 - Escrever um programapara ler: peso atual, peso ideal e perda mensal; exibir em quantos dias a pessoa alcançará o peso ideal. 
int main(void) {
  float pesoAtual, pesoIdeal, perdaMensal;
  printf("Digite o seu peso atual: ");
  scanf("%f", &pesoAtual); //120
  printf("Digite o seu peso ideal: ");
  scanf("%f", &pesoIdeal); //80
  printf("Digite a sua perda mensal: ");
  scanf("%f", &perdaMensal);//5
  printf("Voce vai perder peso em %.2f dias", (pesoAtual-pesoIdeal)/perdaMensal*30);//240 
  return 0;
}

#include <stdio.h>
// QUESTÃO 5 - Solicitar a distância que o usuário pretende correr e a velocidade média esperada. exibir o tempo estimado de exercício. 
int main(void){ 
  float distancia, velocidade; 
  printf("Digite a distancia que pretende percorrer: ");//60 
  scanf("%f", &distancia); 
  printf("Digite a velocidade media esperada: ");//4
  scanf("%f", &velocidade); printf("O tempo estimado de exercicio eh: %.2f ",distancia/velocidade);//15 
  return 0;
}
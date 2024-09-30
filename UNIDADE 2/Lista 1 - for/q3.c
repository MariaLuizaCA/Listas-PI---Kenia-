/* 
ENTRADA: receber o numero de passageiros por h(8-18h)
PROCESSAMENTO: calcular a media,  achar o horário com menor número de passageiros, ganho do dia(22 reais a passagem), a soma de todos os passageiros do dia 
SAIDA: horário com menor passageiros, a média de passageiros no dia, a soma de todos os passageiros do dia e o quanto ela ganhou 
 */

#include <stdio.h>

float media(int total){
  return (float) total/11;
}

int main(void){
  int passageiros, menorPassageiros = -1, horaMenor, total=0;
  float ganho;
  for (int cont = 8; cont<19; cont++){
    printf("Digite o numero de passageiros das %d h: ", cont);
    scanf(" %d", &passageiros);

    total += passageiros; //vai ficar atualizando

    if(menorPassageiros  == -1 || passageiros < menorPassageiros){
      menorPassageiros = passageiros;
      horaMenor = cont; 
    }
  }
  float mediaPass = media(total);
  ganho = total * 22;

  printf("A hora com menor quantidade de passageiros eh: %d\n",horaMenor);
  printf("O total de passageiros no dia eh: %d\n",total);
  printf("A media de passageiros no dia eh: %.2f\n",mediaPass);
  printf("A Dr. ganhou no fim do dia: R$%.2f",ganho);

}
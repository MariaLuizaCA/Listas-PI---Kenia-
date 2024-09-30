/* QUESTAÕ 1 
ENTRADA - peso inicial e o peso almejado
EXIBIR - o peso alcançado (em teoria) a cada mês 
ATENÇÃO - corrigir os erros de quando o peso almejado não multiplo de 5 e o peso inicial ser menor que 0
*/
#include <stdio.h>

float dietaSaturno (float pesoInicial, float pesoAlmejado){
  for (int cont = 1; pesoInicial>pesoAlmejado; cont++){
    pesoInicial = pesoInicial - 5;
    if (pesoInicial > pesoAlmejado){
      printf("Peso alcançado no mes %d: %.2f \n", cont, pesoInicial);
    }
    if(pesoInicial < pesoAlmejado ){
      printf("No proximo mes o peso almejado será ultrapassado\n");
     }
    if(pesoInicial == pesoAlmejado ){
      printf("Peso alcançado no mes %d: %.2f \nVocê alcançou o peso desejado no mes %d!!!", cont, pesoInicial, cont);
    }
  }
}
int main(void) {
  float pesoInicial, pesoAlmejado;
  printf("Digite o seu peso inicial: ");
  scanf("%f", &pesoInicial); //120
  printf("Digite o seu peso ideal: ");
  scanf("%f", &pesoAlmejado); //80

  if (pesoInicial<=0 || pesoInicial<pesoAlmejado){
    printf("O peso recebido nao eh valido");
  } else {
    dietaSaturno(pesoInicial, pesoAlmejado);
  }
}
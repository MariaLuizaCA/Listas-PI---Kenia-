/* Receber numero X (int) de comprimidos ao mês e número de comprimidos N (int) na caixa; 
entregar número de caixas q devem ser compradas*/

#include <math.h>
#include <stdio.h>

int numCaixas(int x, int n) {
  float caixas;
  caixas = (float) x / n; // para garantir q a divisão seja float
  caixas = ceil(caixas); //arredonda para cima 
  return (int)caixas;
}

int main(void) {
  int compMes, compCaixa;
  printf("Digite o número de comprimidos por mês: ");
  scanf("%d", &compMes); //90
  printf("Digite o número de comprimidos por caixa: ");
  scanf("%d", &compCaixa); //20
  printf("O numero de caixas necessarias sao: %d",
         numCaixas(compMes, compCaixa)); //5
  return 0;
}
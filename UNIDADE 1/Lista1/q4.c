#include <stdio.h>
//QUESTÃO 4 - Solicitar um valor monetário em reais, o câmbio real-dolar, e exiba o valor em dólares. 
int main(void) { 
  float reais, cambioReal;
  printf("Digite o valor que deseja converter: ");//75
  scanf("%f", &reais);
  printf("Digite o valor do cambio: ");//5.25
  scanf("%f", &cambioReal);
  printf("O valor convertido eh: %.2f", reais*cambioReal);//393.75
  return 0;
}
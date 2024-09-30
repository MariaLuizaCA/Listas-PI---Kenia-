/*8. Receber: um valor em reais, taxa de câmbio do euro e do dolar
Exibir: o valor convertido em dolares e em euros
*criar função pra essa converção e dois parâmetros de saída* */

#include <stdio.h>
#include <math.h>


float cambio( float v, float cambioDolar, float cambioEuro, float *dolar1, float *euro1){//*dolar1 e *euro1 são parâmetros de saida que armazenam o endereço da variável que será retornada, modificando o valor dela.
  *dolar1 = v * cambioDolar;
  *euro1 = v * cambioEuro;
}  
int main(void) {
  float v, cambioDolar, cambioEuro, dolar1, euro1;

  printf("Digite o valor que voce quer converter: ");//5.25
  scanf("%f", &v);
  printf("Digite a taxa de cambio do dolar: ");//7
  scanf("%f", &cambioDolar);
  printf("Digite a taxa de cambio do euro: ");//
  scanf("%f", &cambioEuro);

  cambio(v, cambioDolar, cambioEuro, &dolar1, &euro1); //os parâmetros de saida são chamados por referência, ou seja, precisa do & para ser acessado

  printf("O valor em dolar eh: %.2f\nO valor do euro eh: %.2f", dolar1, euro1);// dollar = 36.75 e euro = 40.69
}
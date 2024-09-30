/*7.Receber: valor investido inicialmente, valor investido mensalmente e do tempo de investimento 
Exibir: valor final (montante) e o valor do rendimento (montante - valor inicial investido)
*criar função para calcular com dois parâmetros de saída*
*/

#include <stdio.h>
#include <math.h>

float investimento(float valorInicial, float valorMensal, int tempo, float *montante, float *rendimento){ //PONTEIRO: o '*' representa um parâmetro de saida (armazena o endereço de memória de outra variável) 

  *rendimento = valorMensal*tempo;
  *montante = valorInicial + *rendimento;
}

int main(void){
  float valorInicial, valorMensal, montante, rendimento;
  int tempo;
  printf("Digite o valor investido inicialmente: ");//1000
  
  scanf("%f", &valorInicial);
  printf("Digite o valor investido mensalmente: ");//500
  scanf("%f", &valorMensal);
  printf("Digite o tempo de investimento: ");//12
  scanf("%d", &tempo);

  investimento(valorInicial, valorMensal, tempo, &montante, &rendimento);

  printf("O valor final do investimento(montante) eh: %.2f\nE o rendimento eh: %.2f",montante, rendimento);//montante = 7000, rendimento = 6000
}
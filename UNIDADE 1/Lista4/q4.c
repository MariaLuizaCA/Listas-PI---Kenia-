/* Escrever programa , sem aplicar resto de divisão (%)
e valor do quociente (/), para calcular a quantidade
de meses contidos numa dada quantidade de dias.
Considerar que todos os meses são compostos por 30 dias
e desprezar o montante de dias que não formam pelo menos
um mês completo (resto).*/

#include <stdio.h>

int main (void){
  int dias, meses = 0;
  printf("Digite a quantidade de dias: ");
  scanf("%d", &dias);
  while (dias>=30){
    dias = dias - 30;
    meses = meses + 1;
  }
  printf("Os dias equivalem a %d mes(es) ", meses) ;
}

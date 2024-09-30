/* 
ENTRADA: valor da compra, numero de parcelas
PROCESSAMENTO: calcular o juros, total e parcelas (cont < 11)
SAIDA: valor total, valor das parcelas, numero do mes
...
Pagamento em 4 meses – Juros: R$100,00 –Total – R$1.400 – Parcela 4 x R$350,33
...
 */
#include <stdio.h>

float calcularJuros(float valor){
  float juros, total, parcela; 
  juros = valor/10; 
  for (int cont = 1; cont<11 ; cont++){
    total = (juros*cont)+valor;
    parcela = total/cont;
    printf("Pagamento em %d mes(es) - Juros: R$%.2f - Total: R$%.2f - Parcela %d x R$%.2f \n\n", cont, juros, total, cont, parcela);
  }
}
int main(void){
  float valor;
  printf("Digite o valor da compra: ");
  scanf("%f", &valor);
  calcularJuros(valor);
}
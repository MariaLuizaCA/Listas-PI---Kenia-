/*Ajustar o código dado de forma que seja exibida o número da compra.*/


#include <stdio.h>
void ValidaCompra(float *L, int *numDeCompra){
  float D;
  printf("Debito: ");
  scanf("%f",&D);
  if (*L - D >= 0){
    printf("Compra possivel! \n");
    printf("O numero da compra eh: %d\n", *numDeCompra);//mostra o numero de compra
    *L = *L - D;
    *numDeCompra = *numDeCompra + 1; //se ele consegue comprar o numero atualiza
  }
  else{
    printf("Compra ""estourarah"" o cartao! \n");
    printf("Limite restante: %.2f \n\n",*L);
  }
}
int main(){
  float Limite;
  int compra = 1; //começa com 1 para a primeira compra
  printf("Limite do cartao: ");
  scanf("%f",&Limite);
  while (Limite>0)
    ValidaCompra(&Limite, &compra);
  printf("Seu limite de compras acabou!");
  return 0;
}
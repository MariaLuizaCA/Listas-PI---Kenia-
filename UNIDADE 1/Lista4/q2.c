/* Ajustar o código dado de forma que seja identificado também quando a
meta da vaquinha foi ultrapassada, passando a haver duas
mensagens de retorno ao usuário, e para, sempre que houver uma
doação, exibir o valor parcial alcançado. */

#include <stdio.h>

int main(void){
  float Meta, Doacao, Soma = 0;
  printf("Meta da vaquinha: ");
  scanf("%f", &Meta);
  do{
    printf("Valor da doacao: ");
    scanf("%f", &Doacao);
    Soma = Soma + Doacao;
    printf("Valor parcial alcancado: %.2f", Soma);
  }
  while (Soma < Meta);
  if (Soma == Meta)
      printf(" A meta foi alcancada!");
  else
    printf("A meta foi ultrapassada!\nO valor alcancado foi: %.2f", Soma);
  return 0;
}
#include <stdio.h>
/* QUESTÃO 6 - Escrever programa em C para solicitar ao usuário um número e
exibir a tabuada (de multiplicação) desse número até 10. !!!! precisar aceitar
números decimais tbm??? */
int main(void) { 
  int numero; 
  printf("Digite um numero para saber sua tabela: "); 
  scanf("%d", &numero); 
  printf(" A tabuada de %d eh:%d x 0 = 0\n%d x 1 = %d\n%d x 2 = %d\n%d x 3 = %d\n%d x 4 = %d\n%d x 5 = %d\n%d x 6 = %d\n%d x 7 = %d\n%d x 8 = %d\n%d x 9 = %d\n%d x 10 = %d", numero, numero, numero, numero*1, numero, numero*2, numero, numero*3, numero, numero*4, numero, numero*5, numero, numero*6, numero, numero*7, numero, numero*8, numero, numero*9, numero, numero*10); //estilo de tabela
  return 0;
}

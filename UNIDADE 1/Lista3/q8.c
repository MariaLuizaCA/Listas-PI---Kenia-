/* Exibir:  menu: U – unidade, D –
dezena, C – centena, M – unidade de milhar e Z –
dezena de milhar
Receber: numero (int) - 0 < numero < 99.999
Exibir: o numero da opção selecionada
usar switch-case, mostrar mensagem de erro, letras maiusculas e minusculas, */

#include <stdio.h>
#include <ctype.h>

int unidade(int num){
  int unid;
  unid = num % 10;
  return unid;
}
int dezena(int num){
  int dez;
  dez = (num % 100) / 10;
  return dez;
}
int centena(int num){
  int cen;
  cen = (num % 1000) / 100;
  return cen;
}
int uniMilhar(int num){
  int uniMil;
  uniMil = (num % 10000) / 1000;
  return uniMil;
}
int dezMilhar(int num){
  int dezMil;
  dezMil = (num % 100000) / 10000;
  return dezMil;
}
int main (void){
  int numero;
  char opcao;
  printf("MENU ----------\nU - unidade;\nD - dezena;\nC - centena;\nM - unidade de milhar;\nZ - dezena de milhar\nSua opção: ");
  scanf("%c", &opcao);
  printf( "Digite um número: ");
  scanf("%d", &numero);
  opcao = toupper(opcao);
  if (numero > 0 && numero < 99999)
    switch (opcao){
      case 'U':
        printf("Unidade: %d", unidade(numero));
        break;
      case 'D':
        printf("Dezena: %d", dezena(numero));
        break;
      case 'C':
        printf("Centena: %d", centena(numero));
        break;
      case 'M':
        printf("Unidade de Milhar: %d", uniMilhar(numero));
        break;
      case 'Z':
        printf("Dezena de Milhar: %d", dezMilhar(numero));
        break;
      default:
        printf("Opçao Invalida!");
    }
  else
    printf("O número não está entre 0 e 99999");

}
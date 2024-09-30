/*QUESTÃO 1 ---
ENTRADA: palavra <=20 caracteres
PROCESSAMENTO: passar para upperCase
SAIDA: palavra inteira maiúscula
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
  char palavra[21];
  int tamanho;

  printf("Digite a palavra que deve ser maiuscula [com até 20 caracteres ]: ");
    scanf("%[^\n]s",palavra);
  if (strlen(palavra) <= 20){
    for (int i = 0; i < strlen(palavra); i++ ){
      palavra[i] = toupper(palavra[i]);
    }
    printf("A palavra eh: %s", palavra);
  } else {
    printf("A palavra tem mais de 20 caracteres");
  }
}

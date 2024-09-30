/*QUETÃO 2 ---
ENTRADA: receber um nome 
SAIDA: exibir a inicial maiúscula e o
restante minúscula.

● Cadeia[P] = toupper(Cadeia[P]);
Converte a letra da posição P da string
Cadeia para maiúscula, da biblioteca
ctype.h.
● Cadeia[P] = tolower(Cadeia[P]);
Converte a letra da posição P da string
Cadeia para minúscula, da biblioteca
ctype.h.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void){
  char nome[51];
  printf("Digite um nome com 50 caracteres: ");
  scanf("%[^\n]s",nome);
  nome[0] = toupper(nome[0]);
  for (int i = 1; i < strlen(nome); i++ ){
    nome[i] = tolower(nome[i]);
  }
  printf("O nome ficou:\n %s", nome);
}

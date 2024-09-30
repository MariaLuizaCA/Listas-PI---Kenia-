/*QUESTÃO 3 --- (precisa de função e de repetição)
Escrever programa para ler uma palavra P qualquer
com até 20 caracteres e identificar quantas vogais P
apresenta. Aplicar função definida pelo programador
Efetuar essa operação para tantas strings quantas o usuário
desejar.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contadorVogais(char palavra[21], int cont){
  for (int i = 0; i < strlen(palavra); i++ ){
    palavra[i] = tolower(palavra[i]);
  }
  for (int aux = 0; aux < strlen(palavra); aux ++){
    if (palavra[aux] == 'a' || palavra[aux] == 'e' || palavra[aux] == 'i' || palavra[aux] == 'o' || palavra[aux] == 'u' )//falta contabilizar as palavras com acentuação
      cont ++; 
  }
  return cont;
}

int main(void){
  char p[21], r = 's';
  int cont = 0;
  do {
    printf("Digite uma palavra de ate 20 caracteres: ");
    scanf("%[^\n]s",p);
    fflush(stdin);
    printf("Esse nome possui %d vogais \n", contadorVogais(p, cont));

    printf("Digite 's' se deseja contar vogais novamente: \n");
    scanf(" %c",&r);
    getchar();
  } while (r == 'S' || r == 's');
}
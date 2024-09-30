/*QUETÃO 5 --- (precisa criar função)
ENTRADA: matricula de 10 digitos de 100 alunos
0-3: ano de entrada
4-5: numero do curso
97 = agroecologia 
99 = gerontologia 
SAIDA: numero de alunos q entraram em no ano A NO CURSO DE GERONTOLOGIA  
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int inscGeront(char matricula[], char anoA[] ){
  char anoMatric[5], curso[3];
  strncpy(anoMatric, matricula, 4);//só os quatro primeiros
  anoMatric[4] = '\0';

  strncpy(curso, matricula + 4, 2);//a copia começa 4 caracteres depois para pegar a matrícula
  curso[2] = '\0';

  if (curso[0] == '9' && curso[1] == '9' && strcmp(anoMatric, anoA) == 0){
    return 1;
  } else {
    return 0;
  }
}


int main(void){
  char anoA[5], matricula[11];
  int cont = 0;

  printf("Digite o ano que vai ser pesquisado: ");
  scanf(" %4s",anoA);


  for (int aux = 1; aux<4; aux++){
    printf("\nDigite a matriculua do aluno %d: ",aux);
    scanf(" %10s",matricula);

    cont += inscGeront(matricula, anoA);
  }

printf("O numero de alunos de Gerontologia inscritos no ano de %s eh: %d", anoA, cont);
}
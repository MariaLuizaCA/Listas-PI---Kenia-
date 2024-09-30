/* Ler notas de alunos e identificar se cada foi aprovado.
Considerar como sistema de avaliação: em princípio, 3
notas; são aprovados os alunos com média 7; para os
alunos com média acima de 3, é possibilitado fazer 4a
avaliação, então a média passa a ser 5 para obtenção da
aprovação. Após a identificação de que um aluno foi
aprovado, ou não; deve ser questionado se o usuário (do
programa) deseja verificar a situação de outro aluno.*/

#include <stdio.h>

float media(float n1, float n2, float n3){
  float m;
  m = (n1 + n2 + n3)/3;
  return m;
}

int main(void){
  int opcao;
  do { 
    float nota1, nota2, nota3, med;
    printf("Digite suas notas (3): ");
    scanf("%f%f %f", &nota1, &nota2, &nota3);

    med = media(nota1, nota2, nota3);

    if (med >= 7)
      printf("APROVADOOOO\n");
    else if (med >= 3)
      printf("Em recuperacao\n");
        else
          printf("Reprovado\n");

    printf("Deseja verificar a situacao de outro aluno? ( 1 - sim; 2 - nao)\n");
    scanf("%d", &opcao);
  } 
  while(opcao == 1);
  return 0;
}
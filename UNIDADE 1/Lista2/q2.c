/* Receber o número total de alunos matriculados (int), o número max de alunos por turma (int); 
entregar o número de turmas formadas */

#include <stdio.h>
#include <math.h>

int turma(int alunosMatricula, int alunosTurma){
  float numTurmas;
  numTurmas = (float) alunosMatricula / alunosTurma;//garantir que a divisão seja float
  numTurmas = ceil(numTurmas);//arredondar para cima
  return (int)numTurmas;
}

int main(void) {
  int matriculas, maxTurma;
  printf("Digite o numero de alunos matriculados: ");
  scanf("%d", &matriculas);//1145
  printf("Digite o numero de alunos por turma: ");
  scanf("%d", &maxTurma);//50
  printf("O numero de turmas a serem formadas eh: %d", turma(matriculas, maxTurma));//23
}
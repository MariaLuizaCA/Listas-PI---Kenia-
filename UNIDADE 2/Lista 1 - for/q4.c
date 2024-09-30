/* 
ENTRADA: receber 12 notas de 50 alunos 
PROCESSAMENTO: 5 notas >= 7
SAIDA: se foi aprovado ou reprovado

Na disciplina “Programação Imperativa” há 50 alunos e 12  avaliações. Para obtenção de aprovação o aluno deve ter no  mínimo 5 notas maior ou igual a 7. Escrever programa para  ler notas de cada um dos 50 alunos e identificar se foi  aprovado. 
 */

#include <stdio.h>

int main(void){
  float notas;
  int contAprov; 
  for (int aluno = 1; aluno<51; aluno++){
    contAprov = 0;//reiniciar o contador de notas aprovadas
    printf("\nALUNO %d:\n",aluno);
    for(int ava = 1; ava < 13; ava++){  
      printf("Digite a nota da avaliacao %d: ", ava);
      scanf(" %f", &notas);

      if(notas >= 7){
        contAprov++; 
      }
    }
    if (contAprov >= 5){
      printf("O aluno %d foi aprovado!", aluno);        
    } else {
      printf("O aluno %d foi reprovado :( ", aluno);
    }
  }
}
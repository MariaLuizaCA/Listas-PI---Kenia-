/*ENTRADA: nome, 3 notas e frequência (em percentual) dos 80 alunos
SAIDA: exibir nome de cada aluno, seguido das notas, média e situação - APROVADO ou REPROVADO
APROVADO --> média maior q a da turma e frequência acima de 65%   */

#include <string.h>
#include <ctype.h>
#include <stdio.h>


typedef struct {
    char nome[21];
    float nota1;
    float nota2;
    float nota3;
    int frequencia;
} TpAluno;

int main(void) {
    TpAluno Vetor[80];

    for (int cont = 1; cont < 3; cont++) {
        printf("\nDigite o nome do aluno %d: ",cont);
        fgets(Vetor[cont].nome, 21, stdin);
        Vetor[cont].nome[strcspn(Vetor[cont].nome, "\n")] = '\0';

        printf("\nDigite as notas----\nNOTA 1: ");
        scanf("%f", &Vetor[cont].nota1);
        printf("NOTA 2: ");
        scanf("%f", &Vetor[cont].nota2);
        printf("NOTA 3: ");
        scanf("%f", &Vetor[cont].nota3);

        printf("Digite a frequencia (em percentual): ");
        scanf("%d", &Vetor[cont].frequencia);
      
        while (getchar() != '\n');
        }
    


    printf("\nResultados:\n");
    for (int cont = 1; cont < 3; cont++) {
      float media = (Vetor[cont].nota1 + Vetor[cont].nota2 + Vetor[cont].nota3) / 3.0;
      if(media >= 6 && Vetor[cont].frequencia >= 65){
          printf("\n%s - Notas: %.2f, %.2f, %.2f - Frequencia: %d%% - Situacao: APROVADO", 
     Vetor[cont].nome, Vetor[cont].nota1, Vetor[cont].nota2, Vetor[cont].nota3);
      } else {
        printf("\n%s - Notas: %.2f, %.2f, %.2f - Frequencia: %d%% - Situacao: REPROVADO", 
       Vetor[cont].nome, Vetor[cont].nota1, Vetor[cont].nota2, Vetor[cont].nota3);
    }        
  }
}
/* Receber: 3 notas de um aluno
Exibir: a situação do aluno 
media ponderada: (ni*1 + n2*2 + n3*3)/10 
REPROVADO - media<5
EM RECUPERAÇÃO - 7>media>=5
APROVADO - media>7*/

float media(float nota1, float nota2, float nota3){
  float media;
  media = (nota1 + nota2*2 + nota3*3)/6;
  return media;
}
int main(void){
  float nota1, nota2, nota3, m;
  printf("Digite suas notas (3): ");//(7.9,4.2,3.4)(0, 6.4, 8.3)(8, 6.2, 7.8)
  scanf("%f%f %f", &nota1, &nota2, &nota3);
  m = media(nota1, nota2, nota3);//(REPROVADO)(EM RECUPERAÇÃO)(APROVADO)
  if (m >=7)
    printf("APROVADO");
  else
    if(m >=5)
      printf("EM RECUPERACAO");
    else
      printf("REPROVADO");
}
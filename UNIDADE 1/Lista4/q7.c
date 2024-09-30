/*Entrada: dois numeros inteiros e um float (para quando o primeiro número entregue for <0)
Condições: 80% em portugues, 60% em matemática e nota >=7 em redação 
saida: quantas pessoas passaram(int)
oferecer uma saida mais rebuscada (DESEJA SAIR ? S - SIM N - NÃO)
*/
float aprovar(int notaPort, int notaMat, float notaRed, int *aprovados){
  if (notaPort>=40 && notaMat >= 21 && notaRed >= 7){
    *aprovados = *aprovados + 1;
  }
}

int main (void){
  int portugues, matematica, apro = 0;
  char opcao;
  float redacao;
  do{
    printf("Digite a quantidade de acertos em portugues: ");
    scanf("%d", &portugues);
    printf("Digite a quantidade de acertos em matematica: ");
    scanf("%d", &matematica);
    printf("Digite a nota da redacao: ");
    scanf("%f", &redacao);
    aprovar(portugues, matematica, redacao, &apro);
    printf("Deseja sair? N - nao; S - sim: ");
    scanf(" %c", &opcao);
  } while(opcao == 'N' || opcao == 'n');
  printf("\nO numero total de aprovados eh de: %d", apro);

}
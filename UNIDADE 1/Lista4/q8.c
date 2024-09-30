/*Entrada: um inteiro(1<=n<=40)
saida: a sequência (1 ... M) onde M é o número da iteração atual do laço, que será executado n vezes*/

float iteracao(int n){
  int linha = 1;
  do {

    int aux = 1;// tem q reiniciar antes de começar nova linha
    do {
      printf("%d", aux);
      aux = aux + 1;    
    } while (aux <= linha);

    printf(".\n");
    linha = linha + 1;
  } while (linha<=n);
}

int main(void){
  int n;
  printf("Digite o numero inteiro de 1 a 40: ");
  scanf("%d", &n);
  if (n>= 1 && n <= 40)
    iteracao(n);
  else 
    printf("NUMERO INVALIDO");
}
/* Receber: 3 numeros inteiros( N, A, B) 
Exibir: ATENDE CONDIÇÃO; NÃO ATENDE CONDIÇÃO
condição: N ser dividivel por A e n por B || por B e n por A
*/

#include <stdio.h>

int verificar(int n, int a, int b){
  if(n%a==0 && n%b!=0)
    printf("CONDIÇÃO ATENDIDA");
  else {
    if(n%a!=0 && n%b==0)
      printf("CONDIÇÃO ATENDIDA");
    else
      printf("NÃO ATENDE CONDIÇAO");
  }
}

int main(void){
  int n, a, b;
  printf("Digite três numeros inteiros: ");//(3,4,8)(3,4,9)(3,6,2)(2,4,8)(9,3,2)(10,4,5)
  scanf("%d %d %d", &n,&a,&b);
  verificar(n,a,b);//(não)(não)(não)(não)(sim)(sim)
}
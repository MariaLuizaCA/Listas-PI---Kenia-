#include <stdio.h>

//QUESTÃO 3 - Ler o ano em que a criança toma a primeira dose e o intervalo em anos da vacina e exibir em que outros anos a criança deve tomar o reforço. 
int main(void) { 
  int anoDose, intervaloAno; 
  printf("Digite o ano em que a criança tomou a primeira dose:"); //2016 
  scanf("%d", &anoDose); 
  printf("Digite o intervalo em anos da vacina: ");//4 
  scanf("%d", &intervaloAno); 
  printf("Os anos de vacinaçao vao ser: %d, %d e %d ", anoDose +intervaloAno, anoDose+intervaloAno*2,anoDose+intervaloAno*3);//2020,2024,2028
  return 0;
}
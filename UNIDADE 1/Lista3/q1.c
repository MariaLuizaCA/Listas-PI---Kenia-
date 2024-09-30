/* Receber: número de inscritos no passeio (int)
exibir: número de viagens necessárias e o número de passagens do coletivo 
*/

#include <stdio.h>

int passeio(int inscritos, int *viagens, int *passagem){
  *viagens = inscritos/11;
  *passagem = inscritos%11;
  /*if (*passagem == 0)
    printf("Serao necessarias apenas %d viagens de kombi", *viagens);
  else
    printf("Serao necessarias %d viagens de kombi e %d passagem(ns) em coletivo", *viagens, *passagem);*/
}

int main(void){
  int inscritos, viagens, passagem;
  printf("Informe o namero de inscritos: ");//22 e 37
  scanf("%d", &inscritos);
  passeio(inscritos, &viagens, &passagem);// (2,0)(3,4)
  if (passagem == 0)
    printf("Serao necessarias apenas %d viagens de kombi", viagens);
  else
    printf("Serao necessarias %d viagens de kombi e %d passagem(ns) em coletivo", viagens, passagem);
}
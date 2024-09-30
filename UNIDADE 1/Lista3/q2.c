/*Receber: número de gatos capturados,
Exibir: distribuições entre os veterinários
*numGatos<=4 conjunto de veterinarios* 
4 veterinarios e 1 recém formado
1- todos participam
2- todos participam - o recém formado
3- todos participam + o recém formado
*/

#include<stdio.h>

int castracao(int numGatos){
  int quantVet, restoVet;
  if (numGatos<=4)
    printf("Todos os veterinarios experientes participarao da castraçao");
  else 
    if(numGatos%4==0){
      quantVet=numGatos/4;
      printf("Cada veterinario experiente tera %d gatos", quantVet);
    }else{
      quantVet=numGatos/4;
      restoVet = numGatos%4;
      printf("Cada veterinario experiente tera %d gatos e o recem formado %d gato(s)", quantVet, restoVet);      
    }
}

int main(void){
  int numGatos;
  printf("Quantos gatos foram coletados: ");//(3)(12)(23)
  scanf("%d", &numGatos);
  castracao(numGatos);//(opção 1)(opção 2)(opção 3)
}

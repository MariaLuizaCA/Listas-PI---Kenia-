/*QUESTÃO 1 -----
Implementar opções de 4 a 8.*/

#include <stdio.h>
#include <string.h>

float M[4][6]={{385,534,309,546,503,477},
        {12, 121, 12, 3, 24, 12},
        {35.9, 72.1, 46.2,74.3,78,90},
        {-28, -18, -18, -18, -22, -18}};

int Frz, Crc;

void ExibeMatriz(float Matriz[][6],int L,int C){
  printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
  for(int i=0;i<L;i++){
    if (i==0) printf("Capacidade (litros) ");
    if (i==1) printf("Garantia (meses)    ");
    if (i==2) printf("Economia (KWh/mes)  ");
    if (i==3) printf("Temperatura Min (C) "); 
    for (int j=0; j<C; j++)
      printf("%6.1f",Matriz[i][j]);
    printf("\n");
  }
}

void ExibeColuna(float Matriz[][6],int L,int C){
  for(int i=0;i<L;i++){
    if (i==0) printf("Capacidade (litros) ");
    if (i==1) printf("Garantia (meses)    ");
    if (i==2) printf("Economia (KWh/mes)  ");
    if (i==3) printf("Temperatura Min (C) ");
    printf("%6.1f\n",Matriz[i][C]);
  }
}

void ExibeLinha(float Matriz[][6],int L,int C){
printf("Deia   Sul  NSul  Frio   Fri   Lux \n");
for(int i=0;i<C;i++)
  printf("%.1f ",Matriz[L][i]);
printf("\n");
}

void SelecionaFreezer(float Matriz[][6],int *F){
  printf("Selecione o freezer desejado:\n");
  printf("1 - Deia\n");
  printf("2 - Sul\n");
  printf("3 - NSul\n");
  printf("4 - Frio\n");
  printf("5 - Fri\n");
  printf("6 - Lux\n\n");
  printf("Opcao: ");
  int Op;
  scanf("%d",&Op);
  *F=Op-1;
}

void SelecionaCaracteristica(float Matriz[][6],int *C){
  system("cls");
  printf("Caracteristica desejado\n");
  printf("1 - Capacidade (litros)\n");
  printf("2 - Garantia (meses)\n");
  printf("3 - Economia(kWh/mes)\n");
  printf("4 - Temperatura Minima (Celsius)\n");
  printf("Opcao: ");
  int Op;
  scanf("%d",&Op);
  *C=Op-1;
}

int alteraDado(float Matriz[][6]){
  SelecionaCaracteristica(Matriz, &Crc);
  SelecionaFreezer(Matriz, &Frz);
  float dado;
  printf("Digete o dado ser preenchido: ");
  scanf(" %f", &dado);
  Matriz[Crc][Frz] = dado;
  ExibeMatriz(Matriz, 4, 6);
}

int melhorAlgumaCoisa(float Matriz[][6], int linha){
  float cap = Matriz[linha][0];
  int ind = 0;
  for (int c = 1; c < 6; c++ ){
    if (Matriz[linha][c] > cap){
        cap = Matriz[linha][c];
        ind = c;
      }
  }
  freezerNome(ind+1);
  ExibeMatriz(Matriz, 4, 6);
}

int melhorTemperatura(float Matriz[][6], int linha){
  float cap = Matriz[linha][0];
  int ind = 0;
  for (int c = 1; c < 6; c++ ){
    if (Matriz[linha][c] < cap){
        cap = Matriz[linha][c];
        ind = c;
        printf("%d", cap);
    }
  }
  freezerNome(ind+1);
  ExibeMatriz(Matriz, 4, 6);
}

int freezerNome(int coluna){
  if (coluna==1) printf( "\nDeia\n");
  else if (coluna==2) printf( "\nSul\n");
  else if (coluna==3) printf( "\nNSul\n");
  else if (coluna==4) printf( "\nFrio\n");
  else if (coluna==5) printf( "\nFri\n");
  else if (coluna==6) printf( "\nLux\n");
}
int main(void){
  do{
    //system("cls");
    printf(">>> Pesquisa Freezer <<<\n\n");
    printf("Selecione a opcao desejada:\n");
    printf("1 - Exibir Levantamento\n");
    printf("2 - Dados de um Freezer\n");
    printf("3 - Dados de uma Caracteristica\n");
    printf("4 - Alterar Dado\n");
    printf("5 - Melhor Freezer em Capacidade\n");
    printf("6 - Melhor Freezer em Garantia\n");
    printf("7 - Melhor Freezer em Economia\n");
    printf("8 - Melhor Freezer em Temperatura\n");
    printf("9 - Sair\n");
    int Op;
    scanf("%d",&Op);
    switch (Op){
      case 1: ExibeMatriz(M,4,6);
              //system("pause");
              break;
      case 2: SelecionaFreezer(M,&Frz);
              ExibeColuna(M,4,Frz);
              //system("pause");
              break;
      case 3: SelecionaCaracteristica(M,&Crc);
              ExibeLinha(M,Crc,6);
              //system("pause");
              break;
      case 4: alteraDado(M);
              //system("pause");
              break; 
      case 5: printf("\nO melhor freezer em capacidade eh:  \n");
              melhorAlgumaCoisa(M, 0);
              //system("pause");
              break;
      case 6: printf("\nO melhor freezer em garantia eh:  \n");
              melhorAlgumaCoisa(M, 1);
              break;
      case 7: printf("\nO melhor freezer em economia eh:  \n");
              melhorAlgumaCoisa(M, 2);
              break;
      case 8: printf("\nO melhor freezer em temperatura eh:  \n");
              melhorTemperatura(M, 3);
              break;
      case 9: break;}
      if (Op==9)
        break;
  } while (1);
  return 0;
}
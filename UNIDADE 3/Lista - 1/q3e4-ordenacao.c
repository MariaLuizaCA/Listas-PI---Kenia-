/*(03) 
Pesquisar método de classificação de
dados diferente do trabalhado em sala de
aula, recursivo, e apresentar de forma
semelhante à do slide 64 
(04) implementá-lo
aplicando a vetor composto por 25 palavras
(previamente definidas e desordenadas).*/


#include <stdio.h>
#include <string.h>

// troca as palavras de posição
void trocar(char *palavra1, char *palavra2) {
  char temp[30];

  strcpy(temp, palavra1);
  strcpy(palavra1, palavra2);
  strcpy(palavra2, temp);
}

//ele divide o vetor de palavras
int particionar(char vetor[][30], int inicio, int fim) {
  char pivo[30];

  strcpy(pivo, vetor[fim]);//seleciona a ultima palavra do pivo
  int i = (inicio - 1);

  for (int j = inicio; j <= fim - 1; j++) {

    if (strcmp(vetor[j], pivo) < 0) {//compara a as palavras com o pivo
      i++;
      trocar(vetor[i], vetor[j]);//troca as palavras se for menor
    }
  }

  trocar(vetor[i + 1], vetor[fim]);
  return (i + 1);
}

//recursividade para realizar o quick
void quickSortRecursivo(char vetor[][30], int inicio, int fim) {

  if (inicio < fim) {
    int indicePivo = particionar(vetor, inicio, fim);
//ordena antes e depois do pivo
    quickSortRecursivo(vetor, inicio, indicePivo - 1);
    quickSortRecursivo(vetor, indicePivo + 1, fim);
  }
}

void quickSort(char vetor[][30], int tamanho) {
  quickSortRecursivo(vetor, 0, tamanho - 1);
}

int main() {

  char palavras[25][30] = {
      "banana", "laranja",  "abacaxi",   "uva",        "limao",     "morango",
      "pera",   "melancia", "maça",      "abacate",    "kiwi",      "manga",
      "cereja", "goiaba",   "melao",     "abacate",    "tangerina", "ameixa",
      "caqui",  "pêssego",  "framboesa", "jabuticaba", "coco",      "figo"};

  int tamanho = sizeof(palavras) / sizeof(palavras[0]);

  printf("Palavras desordenadas:\n\n");

  for (int i = 0; i < tamanho - 1; i++) {
    printf("%s - ", palavras[i]);
  }
  printf("\n");

  quickSort(palavras, tamanho);

  printf("\nPalavras ordenadas:\n\n");

  for (int i = 0; i < tamanho; i++) {
    printf("%s - ", palavras[i]);
  }

  printf("\n");

  return 0;
}
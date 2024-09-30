/*Ajustar o subprograma considerando que o vetor deve ser composto por strings:*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>


int bbinaria (char chave[], int inicio, int fim, char vetor[][30]) {
  if (fim < inicio)
    return -1;
  else {
    int meio = (inicio + fim)/2;

    if (strcmp(vetor[meio], chave) == 0)
      return meio;
    else {
      if (strcmp(vetor[meio], chave) < 0)
        return bbinaria (chave, meio+1, fim, vetor);
      else
        return bbinaria (chave, inicio, meio-1, vetor);
    }
  }
}


int main() {
    char vetor[6][30] = {"Duda", "Jorge", "Laura", "Luceilma", "Malu", "Maru", "Sophia"};

    char chave[] = "Malu";

    int ind = bbinaria(chave, 0, 6, vetor);

    if (ind != -1) {
        printf("'%s' encontrado na posição %d.\n", chave, ind+1);
    } else {
        printf("'%s' não encontrado.\n", chave);
    }

    return 0;
}
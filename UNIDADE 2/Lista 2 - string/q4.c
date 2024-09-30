#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char nomeCompleto[50], nome[20], sobrenome[20], copia[50]; 

    printf("Digite seu nome e sobrenome: ");
    fgets(nomeCompleto, sizeof(nomeCompleto), stdin);
    nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0'; 

    strcpy(copia, nomeCompleto);

    int pos = 0;

    for (int aux = 0; copia[aux] != '\0'; aux++) {//posição do espaço
        if (copia[aux] == ' ') {
            pos = aux;
            break;
        }
    }
    for (int aux = pos + 1; copia[aux] != '\0'; aux++) {//passa para maiuscula
        copia[aux] = toupper(copia[aux]);
    }
    for (int aux = 0; aux < pos; aux++) { //nome em minúscula e a primeira grande
        if (aux == 0) {
            nome[aux] = toupper(nomeCompleto[aux]);
        } else {
            nome[aux] = tolower(nomeCompleto[aux]);
        }
    }
    nome[pos] = '\0';
    printf("%s, %s\n", &copia[pos + 1], nome);

    return 0;
}

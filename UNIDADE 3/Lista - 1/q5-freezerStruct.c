/* Ajustar a principal estrutura de dados usada
no Projeto Freezers de forma a aplicar structs.
Selecionar um módulo que manipule os dados
e reescreva-o considerando a estrutura
proposta por você. É suficiente apresentar o trecho
de código (estrutura e módulo). Na
apresentação/avaliação não é preciso executá-lo. */
#include <stdio.h>
#include <stdlib.h>


//definição das estruturas
typedef struct {
    float capacidade;
    int garantia;
    float economia;
    float temperatura;
} Freezer;

Freezer freezers[6] = {
    {385, 12, 35.9, -28}, // Deia
    {534, 12, 72.1, -18}, // Sul
    {309, 12, 46.2, -18}, // NSul
    {546, 3, 74.3, -18},  // Frio
    {503, 24, 78, -22},   // Fri
    {477, 12, 90, -18}    // Lux
};

char *nome_freezers[6] = {"Deia", "Sul", "NSul", "Frio", "Fri", "Lux"};

typedef enum {
    CAPACIDADE,
    GARANTIA,
    ECONOMIA,
    TEMPERATURA
} Classificacao;

int melhorFreezer(Classificacao linha) {//procura o melhor freezer recebendo a marcação
    int melhor_index = 0;
    float melhor_valor;

    // Define o valor inicial da variavel
    switch (linha) {
        case CAPACIDADE:
            melhor_valor = freezers[0].capacidade;
            break;
        case GARANTIA:
            melhor_valor = freezers[0].garantia;
            break;
        case ECONOMIA:
            melhor_valor = freezers[0].economia;
            break;
        case TEMPERATURA:
            melhor_valor = freezers[0].temperatura;
            break;
    }

    for (int i = 1; i < 6; i++) {//percorre os freezers
        switch (linha) {
            case CAPACIDADE:
                if (freezers[i].capacidade > melhor_valor) {
                    melhor_valor = freezers[i].capacidade;
                    melhor_index = i;
                }
                break;
            case GARANTIA:
                if (freezers[i].garantia > melhor_valor) {
                    melhor_valor = freezers[i].garantia;
                    melhor_index = i;
                }
                break;
            case ECONOMIA:
                if (freezers[i].economia > melhor_valor) {
                    melhor_valor = freezers[i].economia;
                    melhor_index = i;
                }
                break;
            case TEMPERATURA:
                if (freezers[i].temperatura < melhor_valor) {
                    melhor_valor = freezers[i].temperatura;
                    melhor_index = i;
                }
                break;
        }
    }

    return melhor_index;
}

void exibirRegistro() {//exibe o registro todo
    printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
    printf("Capacidade (litros) ");
    for (int j = 0; j < 6; j++) {
        printf("%6.1f", freezers[j].capacidade);
    }
    printf("\nGarantia (meses)    ");
    for (int j = 0; j < 6; j++) {
        printf("%6d", freezers[j].garantia);
    }
    printf("\nEconomia (KWh/mes)  ");
    for (int j = 0; j < 6; j++) {
        printf("%6.1f", freezers[j].economia);
    }
    printf("\nTemperatura Min (C) ");
    for (int j = 0; j < 6; j++) {
        printf("%6.1f", freezers[j].temperatura);
    }
    printf("\n");
}

void dadosFreezer(int marca) { //exibe o freezer e seus dados
    printf("Dados do Freezer %s:\n", nome_freezers[marca]);
    printf("Capacidade: %.1f\n", freezers[marca].capacidade);
    printf("Garantia: %d meses\n", freezers[marca].garantia);
    printf("Economia: %.1f KWh/mes\n", freezers[marca].economia);
    printf("Temperatura Minima: %.1f Celsius\n", freezers[marca].temperatura);
}

void dadosClassificacao(int classMarca) {//exibe as linhas das classificaç~es
    printf("Dados da Caracteristica:\n");
    switch (classMarca) {
        case 0:
            printf("Capacidade (litros):\n");
            for (int i = 0; i < 6; i++) {
                printf("%.1f\n", freezers[i].capacidade);
            }
            break;
        case 1:
            printf("Garantia (meses):\n");
            for (int i = 0; i < 6; i++) {
                printf("%d\n", freezers[i].garantia);
            }
            break;
        case 2:
            printf("Economia (KWh/mes):\n");
            for (int i = 0; i < 6; i++) {
                printf("%.1f\n", freezers[i].economia);
            }
            break;
        case 3:
            printf("Temperatura Minima (Celsius):\n");
            for (int i = 0; i < 6; i++) {
                printf("%.1f\n", freezers[i].temperatura);
            }
            break;
    }
}

void alterarValor(int marca, int classMarca) {
    switch (classMarca) {
        case 0:
            printf("Digite a nova capacidade (litros): ");
            scanf("%f", &freezers[marca].capacidade);
            break;
        case 1:
            printf("Digite a nova garantia (meses): ");
            scanf("%d", &freezers[marca].garantia);
            break;
        case 2:
            printf("Digite a nova economia (KWh/mes): ");
            scanf("%f", &freezers[marca].economia);
            break;
        case 3:
            printf("Digite a nova temperatura mínima (Celsius): ");
            scanf("%f", &freezers[marca].temperatura);
            break;
    }
    printf("Valor alterado com sucesso!\n");
}

// Função principal
int main() {
    int op;
    do {
        system("cls");
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
        scanf("%d", &op);

        switch (op) {
            case 1:
                exibirRegistro();
                break;
            case 2:
                printf("Selecione o freezer desejado (0 a 5): ");
                scanf("%d", &op);
                if (op >= 0 && op < 6)
                    dadosFreezer(op);
                else
                    printf("Freezer selecionado nao existe.\n");
                break;
            case 3:
                printf("Selecione a caracteristica desejada (0 a 3):\n");
                printf("0 - Capacidade (litros)\n");
                printf("1 - Garantia (meses)\n");
                printf("2 - Economia (KWh/mes)\n");
                printf("3 - Temperatura Minima (Celsius)\n");
                scanf("%d", &op);
                if (op >= 0 && op < 4)
                    dadosClassificacao(op);
                else
                    printf("Caracteristica selecionada nao existe.\n");
                break;
            case 4:
                printf("Selecione o freezer desejado (0 a 5): ");
                scanf("%d", &op);
                if (op >= 0 && op < 6) {
                    printf("Selecione a caracteristica desejada (0 a 3):\n");
                    printf("0 - Capacidade (litros)\n");
                    printf("1 - Garantia (meses)\n");
                    printf("2 - Economia (KWh/mes)\n");
                    printf("3 - Temperatura Minima (Celsius)\n");
                    int caracteristica;
                    scanf("%d", &caracteristica);
                    if (caracteristica >= 0 && caracteristica < 4)
                        alterarValor(op, caracteristica);
                    else
                        printf("Caracteristica selecionada nao existe.\n");
                }
                else
                    printf("Freezer selecionado nao existe.\n");
                break;
            case 5:
                printf("Melhor Freezer em Capacidade: ");
                printf("%s\n", nome_freezers[melhorFreezer(CAPACIDADE)]);
                break;
            case 6:
                printf("Melhor Freezer em Garantia: ");
                printf("%s\n", nome_freezers[melhorFreezer(GARANTIA)]);
                break;
            case 7:
                printf("Melhor Freezer em Economia: ");
                printf("%s\n", nome_freezers[melhorFreezer(ECONOMIA)]);
                break;
            case 8:
                printf("Melhor Freezer em Temperatura: ");
                printf("%s\n", nome_freezers[melhorFreezer(TEMPERATURA)]);
                break;
        }
    } while (op != 9);

    return 0;
}
/*Ajustar o módulo de saída do cliente, calculando e exibindo o valor a pagar, lendo o valor pago e calculando o troco. Vocês podem fazer uma proposta de cálculo de valor a pagar considerando horas completas e minutos extras (inferior a 1 hora)*/
/* Considerando a necessidade de construir um programa para definir o valor a pagar pelo uso de um vaga de estacionamento, por tempo de uso. Onde: as vagas são numeradas, o cliente escolhe a vaga em que deseja estacionar seu carro, é registrado no sistema a hora de chegada no estacionamento; exemplo, se um carro chegou às 8:00 no estacionamento e ocupa a vaga 15, na posição 15 do vetor é armazenada a string Placa + hora. Você decide e implementa as operações a serem disponibilizados ao usuário do programa, a necessidade de aplicar subprograma e o valor pela unidade de tempo de uso do estacionamento*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char Estaciona[30][14];
//30 vagas
//Mantem placa com 7 caracteres, sinal de + e 5 caracteres para hora
float Valor, Rendimento = 0;
char Responsavel[21], Iniciou = 0;
int aux[15] = {0}; //QUESTÃO 3 ---- array auxiliar


void AbrirCaixa(){
  //system("cls");
  //system("color 80"); // 8 - cinza  0 - preto
  printf("\n >>> Estacionamento <<< \n");
  printf(" >>>  Largas Vagas  <<< \n");
  printf("\n     ABRINDO  CAIXA \n");   
  for (int i=0; i<30; i++)
     strcpy(Estaciona[i],"LIVRE");
  printf("\nQual o valor do estacionamento por hora de uso? ");
  scanf(" %f",&Valor);
  getchar();
  printf("Qual o nome do responsavel? ");
  fgets(Responsavel, 21, stdin);
  Responsavel[strcspn(Responsavel, "\n")] = 0;
  Iniciou = 1;
}

void ClienteChega(){
  int Vaga;
  char Placa[8], Hora[5], Entrada[14];
  //system("cls");
  //system("color 80"); // 8 - cinza  0 - preto
  fflush(stdin);

  printf("\n >>> Estacionamento <<< \n");
  printf(" >>>  Largas Vagas  <<< \n");
  printf("\n   CHEGADA DE CLIENTE \n");   
  if (Iniciou){
    printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
    printf("\n Responsavel: %s\n\n", Responsavel);
    printf("Qual a vaga ocupada? [1 - 30]");
    scanf("%d",&Vaga);
    getchar();
    if (strcmp(Estaciona[Vaga - 1], "LIVRE") != 0 || Vaga>30 || Vaga < 1){
      printf("A vaga inexistente ou já ocupada");
      return; 
    }

    printf("Qual a placa do veiculo [7 digitos]? ");
    fgets(Placa, 8, stdin);
    Placa[strcspn(Placa, "\n")] = 0;
    strcpy(Entrada,Placa);
    while (getchar() != '\n'); 
    if(strlen(Placa) != 7){
      printf("Placa invalida");
      return;
    }

    printf("Qual a hora de entrada [formato nn:nn]? ");
    fgets(Hora, 6, stdin);
    Hora[strcspn(Hora, "\n")] = 0;
    if(strlen(Hora) != 5 || Hora[2] != ':' ||atoi(Hora) < 6 || atoi(Hora) > 20){
      printf("\nERRO: A hora não está no formato adequado ");
      return;
    }

    strcat(Entrada,"+");
    strcat(Entrada,Hora);
    strcpy(Estaciona[Vaga-1],Entrada);
    printf("Chegada registrada com sucesso!\n");

    aux[atoi(Hora) - 6] ++;
  }
  else
    printf("\nERRO: Antes eh preciso abrir o caixa!\n");
  //system("pause");
}
// QUESTÃO 2 -- Arrumar o modulo de saida, mostrando o valor a pagar e o troco
void ClienteSai(){
  int Vaga;
  char Placa[8], Entrada[14], Hora[3], Min[3], Saida[6], HoraSaida[3], MinSaida[3];
  int H = 0, M = 0, Hs = 0, Ms = 0; //hora, minuto e segundo
  float ValorPagar = 0, Troco = 0, Pago = 0;
  //system("cls");
  //system("color 80"); // 8 - cinza  0 - preto
  fflush(stdin);

  printf("\n >>> Estacionamento <<< \n");
  printf(" >>>  Largas Vagas  <<< \n");
  printf("\n    SAIDA DE CLIENTE \n");   
  if (Iniciou){
    printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
    printf("\n Responsavel: %s\n\n", Responsavel);
    printf("Qual a vaga ocupada? ");
    scanf("%d",&Vaga);
    getchar();

    printf("Qual a hora de saida [formato nn:nn]? ");
    fgets(Saida, 6, stdin);
    Saida[strcspn(Saida, "\n")] = 0;
    fflush(stdin);
    //se vaga LIVRE, houve erro

    strcpy(Entrada,Estaciona[Vaga-1]);

    //Teste
    printf("\n>>>>>>>%s",Entrada);

    for (int i=0; i<7; i++)
      Placa[i] = toupper(Entrada[i]);

     //Teste
     printf("\n>>>>>>>Placa: %s",Placa);

    Hora[0] = Entrada[8];
    Hora[1] = Entrada[9];
    Hora[2] = '\0';
    H = atoi(Hora); // converte string em inteiro
    Min[0] = Entrada[11];
    Min[1] = Entrada[12];
    Min[2] = '\0';
    M = atoi(Min); // converte string em inteiro


    //pegando a hora da saida
    HoraSaida[0] = Saida[0];
    HoraSaida[1] = Saida[1];
    HoraSaida[2] = '\0';
    Hs = atoi(HoraSaida); // converte string em inteiro
    MinSaida[0] = Saida[3];
    MinSaida[1] = Saida[4];
    MinSaida[2] = '\0';
    Ms = atoi(MinSaida); // converte string em inteiro

    //Teste
    printf("\n>>>>>>>Hora de entrada: %d:%d",H, M);
    printf("\n>>>>>>>Hora de saida: %d:%d\n",Hs, Ms);

    int Tempo = (Hs - H)*60 + (Ms - M);
    int DuracaoHora = Tempo/60;
    int DuracaoMin = Tempo%60;

    ValorPagar = DuracaoHora * Valor +  ((float) DuracaoMin / 60) * Valor;
    Rendimento += ValorPagar;

    printf("\nValor a pagar: %.2f\n", ValorPagar);
    printf("\nValor pago: ");
    scanf("%f", &Pago);
    getchar();
    Troco = Pago - ValorPagar;
    printf("Troco: %.2f", Troco);

    strcpy(Estaciona[Vaga - 1], "LIVRE");

    aux[atoi(Hora) - 6]++; //atualizando a array auxiliar QUESTÃO 4 ---
    }
 else
    printf("\nERRO: Antes eh preciso abrir o caixa!\n");
  //system("pause");
}
/*QUESTÃO 3 --- array auxiliar com o quantitativo de carros com entrada em cada horário e exibir um relatório desse quantitativo no módulo FecharCaixa e Alerta de carros ainda no estacionamento. */

/*QUESTÃO 5 --- exibir o horário com maior número de entradas e a soma dos valores recebidos ao longo do dia*/
void FecharCaixa(){

  fflush(stdin);

  printf("\n >>> Estacionamento <<< \n");
  printf(" >>>  Largas Vagas  <<< \n");
  printf("\n - FECHAR CAIXA - \n");
  int HoraPico = 0, Pico = 0;
  if(Iniciou){
      printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
      printf("\n Responsavel: %s\n\n", Responsavel);
      printf("Relatorio:\n");
    for (int cont = 0; cont < 15; cont++ ){
      printf("\nHora de entrada: %d --- Quant. de carros: %d ", cont+6, aux[cont]);
      if(aux[cont] > Pico){
        Pico = aux[cont];
        HoraPico = cont + 6;
      }
    }
    printf("\nHorário de pico: %dh \nNúmero de entradas nesse periodo: %d", HoraPico, Pico);
    printf("\nRendimento total do dia: %.2f\n", Rendimento); 

    for (int cont = 0; cont<30; cont++){
      if(strcmp(Estaciona[cont], "LIVRE") != 0){
        printf("\n CARROS NO ESTACIONAMENTO ");
      }
    }
  }

}

int main(){
  int Op;
  do{
    //system("cls");
    //system("color 70"); // 7 - branco  0 - preto
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n 1 - Abrir Caixa");
    printf("\n 2 - Chegada de Cliente");
    printf("\n 3 - Saida de Cliente");
    printf("\n 4 - Fechar Caixa");
    printf("\n\n Qual a opcao desejada? ");
    do{
      scanf("%d",&Op);
      getchar();
      if ((Op < 1) || (Op > 4)){
        printf("\n ERRO: Opcao invalida!");
        printf("\n Qual a opcao desejada? ");
      }
      else
        break;
    }while (1);
    switch (Op) {
    case 1: AbrirCaixa();
            break;
    case 2: ClienteChega();
            break;
    case 3: ClienteSai();
            break;
    case 4: FecharCaixa();
            break;}
  }while (Op != 4);

return 0;
}
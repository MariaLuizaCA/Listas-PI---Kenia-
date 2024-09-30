#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Fornece: nome, modelo da moto, placa e descrição do defeito. Sabendo que o número máximo de solicitações não passa de 50, escrever programa modularizado para gerenciar os serviços expressos “Zonda”. disponibilizar as opções:*/

struct RegMoto{
  char Nome[20];
  char Modelo[10];
  char Placa[8];//para o '\0'
  char Defeito[50];
  char Status;
  float Preco;
};
typedef struct RegMoto TpRegMoto;
TpRegMoto VZonda[50];

int Quant=-1;//Controla o preenchimento do vetor

/*(1)Solicitar Serviços*/
//melhoria para verificar se a placa já foi previamente cadastrada
void SolicitaServico(){

  char Sair='S';
  do{
    printf("\n\n >>> Motos Zonda <<< \n\n");
    Quant = Quant+1;
    printf("Qual o nome do cliente? ");
    scanf(" %[^\n]s",VZonda[Quant].Nome);
    //Validação do modelo
    do {
        printf("Qual o modelo da moto (max 10 caracteres)? ");
        scanf(" %[^\n]s", VZonda[Quant].Modelo);
        if (strlen(VZonda[Quant].Modelo) > 10) {
            printf("O modelo da moto deve ter no máximo 10 caracteres. Tente novamente.\n");
        }
    } while (strlen(VZonda[Quant].Modelo) > 10);
    //Validação da placa repetição
    int placaValida = 0;
    do{
      printf("Qual a placa da moto? ");
      scanf(" %[^\n]s",VZonda[Quant].Placa);
      for (int i = 0; i < Quant; i++){
        if(strcmp(&VZonda[i].Placa, &VZonda[Quant].Placa) == 0){
          printf("A placa inserida já está no nosso sistema\n");
          placaValida = 1;
        } else {
          placaValida = 0;
        }
      }
    } while(placaValida); 
    printf("Qual o defeito da moto? ");
    scanf(" %[^\n]s",VZonda[Quant].Defeito);
    VZonda[Quant].Status = '0';
    VZonda[Quant].Preco = 0;
    printf("\n\nDeseja inserir novo servico? S|N ");
    scanf(" %c",&Sair);
    Sair=toupper(Sair);
  }
  while (Sair!='N');
}

void IniciaServico(){
/*(2) Iniciar Serviço – quando o status de uma dada moto (placa) é iniciado pelo mecânico e o status para a ser um.*/
  char P[7]; 
  printf("Placa da moto para iniciar serviço: ");
  scanf(" %[^\n]s",P);
  int Pos=-1; //posição da moto P no vetor
  //busca da moto para iniciar serviço
  for (int Cont=0; Cont<=Quant; Cont++)
    if (strcmp(VZonda[Cont].Placa,P)==0)
      Pos=Cont;
  if (Pos==-1)
    printf("Moto não cadastrada!");
  else{
    printf("\n Cliente %d: %s", Pos+1, VZonda[Pos].Nome);
    printf("\n Modelo: %s", VZonda[Pos].Modelo);
    printf("\n Placa: %s", VZonda[Pos].Placa);
    printf("\n Defeito: %s", VZonda[Pos].Defeito);
    VZonda[Pos].Status='1';
    printf("\n Status: %c",VZonda[Pos].Status);
    if (VZonda[Pos].Preco==0)
      printf("\n Preco: NAO DEFINIDO");       
    else
      printf("\n Preco: %.2f",VZonda[Pos].Preco);
  }
}

/*(3) Remover Solicitação – para o caso do proprietário desistir de esperar, o que somente é permitido se o serviço não tiver iniciado, e o status passa a ser dois, dada a placa da moto.*/

void RemoverSolicitacao(){
  char item[8];//\0

  printf("\n\n >>> Motos Zonda <<< \n\n");
  printf("Qual a placa da moto? ");
  scanf(" %s", item);

  for (int i = 0; i < Quant + 1 ; i++){
    if(strcmp(VZonda[i].Placa, item) == 0){
      if(VZonda[i].Status != 1){
        VZonda[i].Status = '2';
        printf("\nA solicitação da placa '%s' foi removida com sucesso", item);
        return;
      } else {
        printf("\nNão é possivel retirar a solicitação da moto, pois o serviço já foi iniciado.");
      }
    }
  }
}


/*(4) Consultar Solicitações – quando se exibe todas as solicitações ainda não feitas (não iniciadas). */
//INCOMPLETA ----------------------------------
void ConsultarSolicitacoes(){
  printf("\n\n >>> Motos Zonda <<< \n\n");
  if (Quant > -1) {
    for (int Cont=0; Cont<=Quant; Cont++){
      if(strcmp(&VZonda[Cont].Status, "0") == 0){
        printf("\n Cliente %d: %s", Cont+1, VZonda[Cont].Nome);
        printf("\n Modelo: %s", VZonda[Cont].Modelo);
        printf("\n Placa: %s", VZonda[Cont].Placa);
        printf("\n Defeito: %s", VZonda[Cont].Defeito);
        printf("\n Status: %c",VZonda[Cont].Status);
        if (VZonda[Cont].Preco==0) 
          printf("\n Preco: NAO DEFINIDO");       
        else
          printf("\n Preco: %.2f",VZonda[Cont].Preco);
        printf("\n --------------------- \n\n");
        }
      }
  } else {
    printf("Não há serviços cadastrados.");
  }
} 

/*(5)Concluir Serviço – para indicar que o mecânico concluiu o atendimento, define o preço final e o status passa a ser três. */

void ConcluirServico(){
  char item[8];//\0
  float preco = 0;
  int ind;

  printf("\n\n >>> Motos Zonda <<< \n\n");
  printf("Qual a placa da moto? ");
  scanf(" %s", item);

  for (int i = 0; i < Quant + 1 ; i++){
    if(strcmp(VZonda[i].Placa, item) == 0){
      if(strcmp(&VZonda[i].Status, "1") == 0){
        VZonda[i].Status = '3';
        ind = i;
        printf("\nO status do serviço de placa %s foi atualizado para finalizado.", item);
        printf("\nQual o valor do serviço? ");
        scanf("%f", &preco);
        VZonda[ind].Preco = preco;
        printf("\n Cliente %d: %s", i+1, VZonda[i].Nome);
        printf("\n Modelo: %s", VZonda[i].Modelo);
        printf("\n Placa: %s", VZonda[i].Placa);
        printf("\n Defeito: %s", VZonda[i].Defeito);
        printf("\n Status: %c",VZonda[i].Status);
        printf("\n Preço: %.2f", VZonda[i].Preco);
        return;
      } else {
        printf("\nA placa não foi encontrada.");
      }
    }
  }
}

/*(6) Encerrar Expediente – para exibição de todos os serviços
efetuados, e exibição do valor total obtido com os serviços. */

void EncerrarExpediente(){
  float lucro = 0;
  int servicosEfetuados = 0; 
  if(Quant == -1){
    printf("Nenhuma solicitação de serviços.");
  } else {
      for(int i = 0; i <= Quant; i++){
        if(strcmp(&VZonda[i].Status, "3") == 0){
          printf("\n Cliente %d: %s", i, VZonda[i].Nome);
          printf("\n Modelo: %s", VZonda[i].Modelo);
          printf("\n Placa: %s", VZonda[i].Placa);
          printf("\n Defeito: %s", VZonda[i].Defeito);
          printf("\n Status: %c",VZonda[i].Status);
          printf("\n Preço: %.2f", VZonda[i].Preco);
          lucro += VZonda[i].Preco;
          servicosEfetuados += 1; 
      }
    }
    printf("\n\nLucro total dos serviços: %.2f", lucro);
  } 
}


int main(){
  int Opcao;
  system("clear"); //limpa tela no ReplIt
  do{
    //Exibicao de menu e leitura da opcao. 	
  printf("\n\n >>> Motos Zonda <<< \n\n");
  printf("1 - Solicitar Servico \n");
  printf("2 - Iniciar Servico \n");
  printf("3 - Remover Solicitacao \n");
  printf("4 - Consultar Solicitacoes \n");
  printf("5 - Concluir Servico \n");
  printf("6 - Encerrar Expediente \n");
  printf("7 - Sair \n\n");
  printf("Digite a opcao desejada: ");
  scanf("%d",&Opcao);	
    switch (Opcao){
    case 1: SolicitaServico(); 
      break;
    case 2: IniciaServico(); 
      break;
    case 3: RemoverSolicitacao(); 
      break;
    case 4: ConsultarSolicitacoes(); 
      break;
    case 5: ConcluirServico(); 
      break;
    case 6: EncerrarExpediente(); 
      break;
    case 7: 
      break;
    }
  }	  	
  while (Opcao!=7);
  return 0;
}
/* Receber: numero (inteiro de 3 digitos)
exibir: numero invertido e se é: NÚMERO GERADO MAIOR QUE NÚMERO LIDO ou
NÚMERO LIDO MAIOR QUE NÚMERO GERADO, ou
ainda, NÚMERO GERADO IGUAL AO NÚMERO
LIDO.*/

#include <stdio.h>

int inverte(int num){
  int centena, dezena, unidade, invertido;
  centena = num/100;
  dezena = (num%100)/10;
  unidade = num%10;
  invertido = unidade*100 + dezena*10 + centena;
  return invertido;
}

int main(void){
  int num, invertido;
  printf("Digite um numero inteiro de 3 digitos: ");//(22)(1000)(123)(321)(222)
  scanf("%d", &num);
  if (num<100||num>999){
    printf("O numero nao eh valido");
  } 
  else {
    invertido = inverte(num);
    if (invertido>num)
      printf("O numero gerado eh maior que o numero lido\n");
    else {
      if (invertido<num)
        printf("O numero lido eh maior que o numero gerado\n");
      else
        printf("O numero gerado eh igual ao numero lido\n"); //(n é valido) (n é valido) (if1) (if2) (if3)
    }
  }
}
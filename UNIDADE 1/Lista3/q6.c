/*Receber: peso(massa) e altura 
exibir: tipo de obesidade da pessoa

TABELA: 
<18,5 -- magreza;
18.5-24.9 -- saudavel;
25-29.9 -- sobrepeso;
30-34.9 -- obesidade grau 1;
35-39.9 -- obesidade grau 2(severa);
>=40 -- obesidade grau 3(morbida).
*/ 
#include <stdio.h>
float imc(float peso, float altura, float *resultado){
  *resultado = peso / (altura * altura);
  return *resultado;
}

int main(void){
  float peso, altura, resultado;
  printf("Digite seu peso: ");//(45)(80)(90)(110)(130)
  scanf("%f",&peso);
  printf("Digite sua altura: ");//(1.69)
  scanf("%f",&altura);
  imc(peso, altura, &resultado);
  if (resultado < 18.5)
    printf("Magreza");
  else {
    if(resultado >= 18.5 && resultado <= 24.9)
      printf("Saudavel");
    else{
      if(resultado>=25 && resultado<=29.9)
        printf("Sobrepeso");
      else{
        if(resultado>=30 && resultado<=34.9)
          printf("Obesidade grau 1");
        else{
          if(resultado>=35 && resultado<=39.9)
            printf("Obesidade grau 2(severa)");
          else
              printf("Obesidade grau 3(morbida)");
        }
      }
    }
  }
}


/*Entrada: receber números aleatórios o último sendo -1.0
Condições:  ACIDA - ph < 7; BASICA - ph > 7; NEUTRA - ph == 7
*/

float analise(float ph){
  if (ph < 7){
    printf("A substancia eh ACIDA");
  } else{
    if (ph > 7){
      printf("A substancia eh BASICA");
    } else {
      printf("A substancia eh NEUTRA");
    }
  }
}

int main(void){
  float ph;
  do {
    printf("\nDigite o ph da substancia: ");
    scanf("%f", &ph);
    if (ph != -1)
      analise(ph);
  } while (ph != -1);
  printf("o programa foi finalizado");
}
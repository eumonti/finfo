#include <stdio.h>
#define NUM_ELEM 10

void printArray(int *arr, int len)
{
  int i;
  for (i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int Ingresso[numeroElementi], Pari[numeroElementi], Dispari[numeroElementi];
  int i;
  int PariInseriti = 0;
  int DispariInseriti = 0;
  for (i = 0; i < numeroElementi; i++)
  {
    scanf("%d", &Ingresso[i]);
    if (Ingresso[i] % 2 == 0)
    {
      Pari[PariInseriti] = Ingresso[i];
      PariInseriti++;
    }
    else
    {
      Dispari[DispariInseriti] = Ingresso[i];
      DispariInseriti++;
    }
  }
  printf("Numeri inseriti:");
  printArray(Ingresso, numeroElementi);
  printf("Numeri pari:");
  printArray(Pari, PariInseriti);
  printf("Numeri dispari:");
  printArray(Dispari, DispariInseriti);
}

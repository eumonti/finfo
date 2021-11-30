#include <stdio.h>
#define NUM_ELEM 10

typedef struct {
  int N;
  int arr[numeroElementi];
} SequentialList;

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
  SequentialList Ingresso, Pari, Dispari;
  Ingresso.N = 0;
  Pari.N = 0;
  Dispari.N = 0;
  for (Ingresso.N = 0; Ingresso.N < numeroElementi; Ingresso.N++)
  {
    scanf("%d", &Ingresso.arr[Ingresso.N]);
    if (Ingresso.arr[Ingresso.N] % 2 == 0)
    {
      Pari.arr[Pari.N] = Ingresso.arr[Ingresso.N];
      Pari.N++;
    }
    else
    {
      Dispari.arr[Dispari.N] = Ingresso.arr[Ingresso.N];
      Dispari.N++;
    }
  }
  printf("Numeri inseriti:");
  printArray(Ingresso.arr, Ingresso.N);
  printf("Numeri pari:");
  printArray(Pari.arr, Pari.N);
  printf("Numeri dispari:");
  printArray(Dispari.arr, Dispari.N);
}

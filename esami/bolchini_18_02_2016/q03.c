/*
Scrivere un sottoprogramma ricorsivo che ricevuto in ingresso un array di interi (e qualsiasi altro parametro ritenuto strettamente necessario) restituisce il numero di "vette" in esso presenti. Si definisce "vetta" un valore presente nell’array maggiore di tutti i valori successivi presenti nell’array.
*/

#include <stdio.h>

#define LENGTH 10

void checkVetta(int arr[LENGTH], int len, int *nVette) // Checks if first el of arr is vetta
{
  printf("%p\n", nVette);
  if (len == 1)
    return;
  checkVetta(arr + 1, len - 1, nVette);
  int i;
  for (i = 1; i < len; i++)
  {
    if (arr[0] <= arr[i])
      return;
  }
  (*nVette)++;
  return;
}

int main()
{
  int nVette = 0;
  printf("%p\n\n", (void *)&nVette);
  int arr[LENGTH] = {2, 3, 4, 10, 8, 7, 5, 6, 4, 3};
  checkVetta(arr, LENGTH, &nVette);
  printf("%d\n", nVette);
}
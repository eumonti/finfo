/*
Si scriva una funzione ricorsiva che ricerchi un valore reale in un array
ordinato di 1000 float. La funzione deve resituire il puntatore
all’elemento dell’array in cui è stato trovato il valore cercato (NULL in
caso di valore assente)
*/

#include <stdio.h>

#define LENGTH 1000

//Binary search
float *search(float *firstEl, float *lastEl, float value)
{
  if (firstEl > lastEl)
    return NULL;
  float *mid = firstEl + ((lastEl - firstEl) / 2);
  if (*mid == value) // Found
    return mid;
  if (value > *mid)
    search(mid + 1, lastEl, value);
  else
    search(firstEl, mid - 1, value);
}

int main()
{
  float arr[LENGTH];
  FILE *data = fopen("data/sorted_arr_1000.txt", "r");
  for (size_t i = 0; i < LENGTH; i++)
    fscanf(data, "%f ", &arr[i]);
  float *result = search(arr, arr + LENGTH, 1.7);
  result ? printf("%ld\n", search(arr, arr + LENGTH, 1.7) - arr) : printf("No luck bro\n");
}
#include <stdio.h>

int main()
{
  char A[] = "abhfbgajetcabfplabwtra"; //40
  int DIM = sizeof(A) / sizeof(A[0]);

  int trovato, T, cont, max, i;
  char *punt;

  trovato = 0;
  T = DIM / 2;
  while (T > 0 && trovato == 0)
  {
    cont = 0;
    max = cont;
    for (i = 0; i < DIM - T; i++)
      if (A[i + T] == A[T])
      {
        cont++;
        if (cont > max)
        {
          max = cont;
          punt = A + i - max + 1;
        }
      }
      else
        cont = 0;
    if (max >= T)
      trovato = 1;
    else
      T--;
  }
  if (trovato)
    printf("Periodo: %d\nPosizione: %lu\nMax: %d\nPrimo carattere: %c\n",
                     T,         (punt - A)/
                                 sizeof(char), max,              *punt);
  else
    printf("Non trovato.\n");
}
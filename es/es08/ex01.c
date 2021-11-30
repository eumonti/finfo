/*
Data una matrice NxM interi, scrivere un programma che scopra se vi sono numeri comuni
a tutte le M colonne e, in caso affermativo, stampi uno degli elementi trovati in comune
(ad esempio il primo elemento trovato).
*/

#include <stdio.h>
#define N 4
#define M 3

int main()
{
  int matrice[N][M] = {
      {1, 1, 1},
      {2, 3, 4},
      {2, 2, 2},
      {2, 3, 5}};
  int i, j;

  i = 0;
  while (i < M)
  {
    for (j = 0; j < N - 1; j++)
    {
      if (matrice[i][j] != matrice[i][j + 1])
      {
        i++;
        break;
      }
      printf("Trovato numero %d\n", matrice[i][j]);
      return 0;
    }
  }
  printf("Nessun numero trovato\n");
}

/*
  * Dato il tipo Matrice, definita come matrice quadrata di N x N interi, con N
  * definita tramite una direttiva define, scrivere un sottoprogramma
  * ricorsivo che calcoli la differenza tra la somma degli elementi della
  * diagonale principale e la somma degli elementi della diagonale
  * secondaria. 
  */

#include <stdio.h>

#define N 3

typedef int Matrice[N][N];

int diagDiff(Matrice m, int order)
{
  if (order == 1)
    return 0;
  return (m[N - order][N - order] - m[N - order][order - 1]) +
         (m[order - 1][order - 1] - m[order - 1][N - order]) +
         diagDiff(m, order - 1);
}

int main()
{
  Matrice m = {{1, 2, 3},
               {4, 10, 6},
               {10, 8, 10}};

  printf("%d\n", diagDiff(m, N));
}
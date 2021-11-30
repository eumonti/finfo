#include <stdio.h>

typedef enum
{
  false,
  true
} bool;

#define N 4 // Ordine matrice

// Tipo matrice
typedef int Matrice[N][N];

bool simmetrica(Matrice m, int order)
{
  if (order == 1)
    return true;
  // Check order - 1 entries
  for (int i = 0; i < order - 1; i++)
  {
    if (m[order - 1][i] != m[i][order - 1])
      return false;
  }
  return simmetrica(m, order - 1);
}

int main()
{
  Matrice m = {{1, 2, 3, 4},
               {2, 5, 6, 7},
               {3, 6, 8, 9},
               {4, 7, 9, 10}};
  simmetrica(m, N) ? printf("La matrice è simmetrica.\n") : printf("La matrice non è simmetrica.\n");
}
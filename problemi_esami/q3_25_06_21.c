#include <stdio.h>
#define L 5

typedef int Matrice[L][L];

void printMatrix(Matrice mat)
{
  int i, j;
  for (i = L - 1; i >= 0; i--)
  {
    for (j = 0; j < L; j++)
    {
      printf("%d\t", mat[i][j]);
    }
    printf("\n");
  }
}

void AttraversaCelle(Matrice mat, float m)
{
  // Determina celle attraversate da y=mx
  int i;
  int j;
  float ySx;
  float yDx;
  for (i = 0; i < L; i++) // Itera colonne
  {
    ySx = m * i;
    yDx = m * (i + 1);
    for (j = (int)ySx; j < yDx && j < L; j++)
    {
      mat[j][i] = 1;
    }
  }
}

int main()
{
  Matrice mat;
  int i, j;
  for (i = 0; i < L; i++)
    for (j = 0; j < L; j++)
      mat[i][j] = 0;

  AttraversaCelle(mat, .5);
  printMatrix(mat);
}

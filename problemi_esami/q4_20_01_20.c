/*
In una matrice di interi, un elemento è un massimo locale se il suo valore supera quello di tutti i suoi vicini
(lungo l’orizzontale o la verticale). Scrivere le dichiarazioni necessarie e una procedura void che, ricevuta
una matrice di interi positivi, la modifichi mantenendo il valore originario solo nei massimi locali, e
assegnando agli altri elementi il valore 0. Ad esempio,

La matrice             ha come matrice dei massimi locali
| 12 11 14 15 |       | 12  0  0  0 |
|  8 15  9 17 |       |  0 15  0 17 |
| 13 10 11 10 |       | 13  0  0  0 |
|  7  6 12 11 |       |  0  0 12  0 |
*/

#include <stdio.h>

#define ROWS 4
#define COLS 4

typedef int Matrice[ROWS][COLS];

void MaxLoc(Matrice mat)
{
  int i, j;
  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      if (
          (i > 0 && mat[i - 1][j] > mat[i][j]) ||
          (i < ROWS - 1 && mat[i + 1][j] > mat[i][j]) ||
          (j < COLS - 1 && mat[i][j + 1] > mat[i][j]) ||
          (j > 0 && mat[i][j - 1] > mat[i][j]))
      {
        mat[i][j] = 0;
      }
    }
  }
}

void printMatrix(Matrice m)
{
  int i, j;
  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  Matrice m = {
      {12, 11, 14, 15},
      {8, 15, 9, 17},
      {13, 10, 11, 10},
      {7, 6, 12, 11}};
  printMatrix(m);
  MaxLoc(m);
  printMatrix(m);
}
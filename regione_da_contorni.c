#include <stdio.h>

#define L 5

typedef int riga[L];
typedef riga matrice[L];

void stampaMatrice(matrice m)
{
  int i, j;
  for (i = 0; i < L; i++)
  {
    for (j = 0; j < L; j++)
    {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  matrice immagine = {{-1, 1, 0, 1, -1},
                      {-1, 1, 0, 1, -1},
                      {-1, 1, 0, 1, -1},
                      {-1, 1, 0, 1, -1},
                      {-1, 1, 0, 1, -1}};
  int i, j;
  int dentro;
  for (i = 0; i < L; i++)
  {
    for (j = 0; j < L; j++)
    {
      if (immagine[i][j] == 1)
        dentro = 1;
      if (immagine[i][j] == -1)
        dentro = 0;
      if (dentro)
        immagine[i][j] = 1;
      else
        immagine[i][j] = 0;
    }
  }
  stampaMatrice(immagine);
}
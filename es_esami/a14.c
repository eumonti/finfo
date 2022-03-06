#include <stdio.h>

#define ROWS 6
#define COLS 10

#define L 5

typedef int Mappa[ROWS][COLS];

int calcola2(Mappa m, int x, int y)
{
  int area;
  if (x == -1 || y == -1 || x == ROWS || y == COLS || // Superato il bordo
      m[x][y] == 0 || m[x][y] == 2)
    return 0;
  m[x][y] = 2;
  area = 1;
  area += calcola2(m, x - 1, y);
  area += calcola2(m, x + 1, y);
  area += calcola2(m, x, y - 1);
  area += calcola2(m, x, y + 1);
  return area;
}

int CalcolaArea(Mappa m, int x, int y)
{
  int i, j;
  int cifraCorrente;
  int area;
  int trovato;
  if (m[x][y] == 0)
  {
    printf("Nessuna regione interconnessa.\n");
    return 0;
  }

  trovato = 1;
  m[x][y]++;
  area = 1;
  cifraCorrente = 2;
  while (trovato)
  {
    trovato = 0;
    for (i = 0; i < ROWS; i++)
    {
      for (j = 0; j < COLS; j++)
      {
        if (m[i][j] == cifraCorrente)
        {
          trovato = 1;
          if (i != 0 && m[i - 1][j] == 1)
          {
            m[i - 1][j] = cifraCorrente + 1;
            area++;
          }
          if (i != ROWS && m[i + 1][j] == 1)
          {
            m[i + 1][j] = cifraCorrente + 1;
            area++;
          }
          if (j != 0 && m[i][j - 1] == 1)
          {
            m[i][j - 1] = cifraCorrente + 1;
            area++;
          }
          if (j != ROWS && m[i][j + 1] == 1)
          {
            m[i][j + 1] = cifraCorrente + 1;
            area++;
          }
        }
      }
    }
    cifraCorrente++;
  }
  return area;
}

int AreaRegioneConnessa(Mappa M, int x, int y)
{
  int cambiato = 1;
  int d;
  int i, j;
  int Area;
  if (x >= 0 && x < L && y >= 0 && y < L && M[x][y] == 1)
  {
    d = 2;
    M[x][y] = 2;
    Area = 1;
  }
  else
    return 0;
  while (cambiato)
  {
    cambiato = 0;
    for (i = 0; i < L; i++)
      for (j = 0; j < L; j++)
        if (M[i][j] == 1)
          if ((i > 0 && M[i - 1][j] == d) ||
              (i + 1 < L && M[i + 1][j] == d) ||
              (j > 0 && M[i][j - 1] == d) ||
              (j + 1 < L && M[i][j + 1] == d))
          {
            cambiato = 1;
            M[i][j] = d + 1;
            Area++;
          }
    d++;
  }
  return (Area);
}

int main()
{
  Mappa m = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
             {0, 1, 1, 0, 0, 1, 1, 0, 1, 1},
             {0, 0, 1, 1, 0, 1, 1, 0, 1, 0},
             {0, 1, 0, 1, 1, 1, 0, 0, 0, 0},
             {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  int area = calcola2(m, 2, 2);
  printf("Area: %d\n", area);
}
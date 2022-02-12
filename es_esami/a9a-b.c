#include <stdio.h>

#define ROWS 6
#define COLS 5

#define R ROWS
#define C COLS

#define OCCUPATA 1
#define LIBERA 0
#define VIETATA -1

typedef int Matrice[ROWS][COLS];

void Aggiorna_a(Matrice m, int x, int y)
{
  int i, j;
  if (m[x][y] == VIETATA)
  {
    printf("Posizione vietata.\n");
    return;
  }
  m[x][y] = OCCUPATA;
  // Aggiorna la matrice aggiungendo le nuove posizioni vietate venutesi a creare dopo l'inserimento del nuovo punto
  for (i = 0; i < ROWS; i++) // (i, j) è la coordinata dell'angolo opposto
  {
    if (x != i)
      for (j = 0; j < COLS; j++)
        if (j != y)
        {
          if (m[i][j] == OCCUPATA && m[x][j] == OCCUPATA)
            m[i][y] = VIETATA;
          if (m[i][j] == OCCUPATA && m[i][y] == OCCUPATA)
            m[x][j] = VIETATA;
          if (m[x][j] == OCCUPATA && m[i][y] == OCCUPATA)
            m[i][j] = VIETATA;
        }
  }
}

// Le righe rappresentano i diversi itinerari
// Le colonne le possibili tappe

// Due itinerari possono contenere al più una tappa comune
void Aggiorna_b(Matrice m, int itinerario, int tappa)
{
  int i, j;
  if (m[itinerario][tappa] == VIETATA)
  {
    printf("Vietato.\n");
    return;
  }
  m[itinerario][tappa] = 1;

  /* Aggiorna la matrice */
  for (i = 0; i < ROWS; i++) // Itera per righe
  {
    if (i != itinerario && m[i][tappa] == 1)
    {
      for (j = 0; j < COLS; j++)
      {
        if (j != tappa && m[itinerario][j] == 1)
        {
          m[i][j] = -1;
        }
      }
    }
  }

  for (i = 0; i < ROWS; i++)
  {
    if (i != itinerario)
      for (j = 0; j < COLS; j++)
      {
        if (j != tappa && m[itinerario][j] == 1 && m[i][j] == 1)
        {
          m[i][tappa] = -1;
        }
      }
  }
}

void AggiungiPunto(Matrice M, int r, int c)
{
  int i, j;
  if (M[r][c] == -1)
  {
    printf("posizione %d %d non valida", r, c);
    return;
  }
  for (j = 0; j <= C; j++)
    /*nel caso generale K può esser sostituito da C */
    if (j != c && M[r][j] == 1)
      for (i = 0; i < R; i++)
        if (M[i][j] == 1)
          M[i][c] = -1;
  for (i = 0; i <= R; i++)
    /*nel caso generale K può esser sostituito da C */
    if (i != r && M[i][c] == 1)
      for (j = 0; j < C; j++)
        if (M[i][j] == 1)
          M[r][j] = -1;
  M[r][c] = 1;
}

int main()
{
  int i, j;
  Matrice m = {
      {1, 0, 0, -1, 0},
      {1, 0, 0, 1, 0},
      {0, 0, 0, 0, 1},
      {0, 0, 0, 0, 1},
      {-1, 0, 0, 1, 0},
      {-1, 0, 0, 1, 0}};
  Aggiorna_b(m, 1, 1);
  // AggiungiPunto(m, 1, 1);
  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }
}
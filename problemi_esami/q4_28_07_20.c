// Nostra pedina: 1
// Loro pedina: -1
// Vuota: 0

#include <stdio.h>

#define GIOCATORE 1
#define AVVERSARIO -1
#define VUOTO 0
#define DIM 8
typedef int Scacchiera[DIM][DIM];

int Salta(Scacchiera board)
{
  int i, j;
  for (i = 0; i < DIM - 2; i++)
  {
    for (j = 0; j < DIM; j++)
    {
      if (board[i][j] == GIOCATORE)
      {

        if (j < DIM - 2 && board[i + 1][j + 1] == AVVERSARIO && board[i + 2][j + 2] == VUOTO)
        {
          board[i][j] = VUOTO;
          board[i + 1][j + 1] = VUOTO;
          board[i + 2][j + 2] = GIOCATORE;
          return 1;
        }
        if (j >= 2 && board[i + 1][j - 1] == AVVERSARIO && board[i + 2][j + 2] == VUOTO)
        {
          board[i][j] = VUOTO;
          board[i + 1][j - 1] = VUOTO;
          board[i + 2][j - 2] = GIOCATORE;
          return 1;
        }
      }
    }
  }
  return 0;
}

void printBoard(Scacchiera s)
{
  int i, j;
  for (int i = DIM - 1; i >= 0; i--)
  {
    for (int j = 0; j < DIM; j++)
    {
      switch (s[i][j])
      {
      case 1:
        printf("B\t");
        break;
      case -1:
        printf("N\t");
        break;

      default:
        printf("-\t");
        break;
      }
    }
    printf("\n\n");
  }
}

int main()
{
  Scacchiera s = {{0, 1, 0, 1, 0, 0, 0, 1},
                  {0, 0, -1, 0, -1, 0, 1, 0},
                  {0, 0, 0, 0, 0, -1, 0, 0},
                  {0, 0, -1, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 1, 0, 0},
                  {0, 0, -1, 0, 1, 0, 1, 0},
                  {0, 0, 0, -1, 0, -1, 0, 0},
                  {0}};
  printBoard(s);
  printf("%d\n\n", Salta(s));
  printBoard(s);
}
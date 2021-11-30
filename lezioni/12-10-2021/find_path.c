#include <stdio.h>

#define N 10

typedef enum
{
  su,
  destra,
  giu,
  sinistra
} Direzione;

typedef struct
{
  int size;
  int data[100];
} Sequence;

void printMatrix(int matrix[N][N])
{
  int i, j;
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}

int readmatrix(size_t rows, size_t cols, int (*a)[cols], const char *filename)
{

  FILE *pf;
  pf = fopen(filename, "r");
  if (pf == NULL)
    return 0;

  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
      fscanf(pf, "%d", a[i] + j);
  }

  fclose(pf);
  return 1;
}

int main()
{
  int i;
  int map[N][N];
  struct
  {
    int row, col;
  } pos;
  Sequence steps;
  steps.size = 0;
  readmatrix(N, N, map, "output.txt");
  printMatrix(map);
  printf("Coordinate da cui iniziare:\n");
  printf("\tRiga: ");
  scanf("%d", &pos.row);
  printf("\tColonna: ");
  scanf("%d", &pos.col);

  if (map[pos.row][pos.col] == -1 || map[pos.row][pos.col] == 1000)
  {
    printf("Impossibile trovare percorso.\n");
    return -1;
  }

  while (map[pos.row][pos.col] > 0)
  {
    if (map[pos.row + 1][pos.col] == map[pos.row][pos.col] - 1)
    {
      pos.row++;
      steps.data[steps.size] = giu;
      steps.size++;
    }
    else if (map[pos.row][pos.col + 1] == map[pos.row][pos.col] - 1)
    {
      pos.col++;
      steps.data[steps.size] = destra;
      steps.size++;
    }
    else if (map[pos.row - 1][pos.col] == map[pos.row][pos.col] - 1)
    {
      pos.row--;
      steps.data[steps.size] = su;
      steps.size++;
    }
    else if (map[pos.row][pos.col - 1] == map[pos.row][pos.col] - 1)
    {
      pos.col--;
      steps.data[steps.size] = sinistra;
      steps.size++;
    }
  }

  for (i = 0; i < steps.size; i++)
  {
    switch (steps.data[i])
    {
    case su:
      printf("Su");
      break;
    case destra:
      printf("Destra");
      break;
    case giu:
      printf("Giu");
      break;
    case sinistra:
      printf("Sinistra");
      break;
    }
    printf(" ");
  }
  printf("\n");
}

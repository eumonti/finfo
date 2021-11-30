#include <stdio.h>

#define N 10

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

int main()
{
  int i, j;
  int curr_dist = 1;
  int map[N][N] = {{-1, -1, -1, -1, 0, 0, -1, -1, -1, -1},
                   {-1, -1, -1, -1, 0, -1, -1, -1, -1, -1},
                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                   {-1, -1, -1, 1000, 1000, 1000, -1, -1, -1, -1},
                   {-1, -1, -1, 1000, -1, -1, -1, -1, -1, -1},
                   {-1, -1, -1, 1000, -1, -1, -1, -1, -1, -1},
                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                   {-1, -1, -1, -1, -1, 1000, 1000, 1000, -1, -1},
                   {-1, -1, -1, -1, -1, 1000, -1, 1000, -1, -1},
                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
  int changed = 1;
  while (changed)
  {
    changed = 0;
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
      {
        if (map[i][j] == -1)
        {
          if ((j < N - 1 && map[i][j + 1] == curr_dist - 1) ||
              (j > 0 && map[i][j - 1] == curr_dist - 1) ||
              (i < N - 1 && map[i + 1][j] == curr_dist - 1) ||
              (i > 0 && map[i - 1][j] == curr_dist - 1))
          {
            changed = 1;
            map[i][j] = curr_dist;
          }
        }
      }
    }
    curr_dist++;
  }
  printMatrix(map);
}
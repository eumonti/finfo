#include <stdio.h>
#define GRADO 6

void CalcolaDerivata(float pol[GRADO + 1])
{
  int i;
  for (i = 0; i <= GRADO; i++)
    pol[i] = pol[i + 1] * (i + 1);

  pol[GRADO] = 0;
}

int main()
{
  float pol[GRADO + 1] = {3, 4, 5, 6, 7, 7, 8};
  for (int i = GRADO; i >= 0; i--)
    printf("%.2fx^%d ", pol[i], i);
  printf("\n");
  CalcolaDerivata(pol);
  for (int i = GRADO - 1; i >= 0; i--)
    printf("%.2fx^%d ", pol[i], i);
  printf("\n");
}
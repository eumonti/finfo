#include <stdio.h>
#include <stdlib.h>

#define grado(arr) sizeof(arr) / sizeof(arr[0])

int max(int a, int b)
{
  return (a > b ? a : b);
}

float *somma(float *a, float *b, int len1, int len2)
{
  int maxlen = max(len1, len2);
  float *risultato = malloc(sizeof(float) * maxlen);
  int i;
  for (i = 0; i < maxlen; i++)
  {
    if (i > len1 - 1 && i <= len2 - 1)
    {

      risultato[i] = b[i];
    }
    else if (i > len2 - 1 && i <= len1 - 1)
    {
      risultato[i] = a[i];
    }
    else
    {
      risultato[i] = a[i] + b[i];
    }
  }
  return risultato;
}

int main()
{
  //              x^0  x^1  x^2
  float pol1[] = {2.0, 3.0, 1.0, 3.0};
  float pol2[] = {1.0, 2.0, 5.0};
  int grado1 = grado(pol1);
  int grado2 = grado(pol2);
  int max_grado = max(grado1, grado2);
  float *risultato = somma(pol1, pol2, grado1, grado2);
  for (int i = 0; i < max_grado; i++)
  {
    printf("%f ", risultato[i]);
  }
  printf("\n");
}
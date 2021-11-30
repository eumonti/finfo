#include <stdio.h>

#define DIM 30

typedef struct
{
  int N;
  float coeff[DIM];
} Polinomio;

float ValorePolinomio(Polinomio P, float x)
{
  int i;
  float valore;
  valore = 0.0;
  for (i = 0; i < P.N; i++)
    valore = valore * x + P.coeff[i];
  return valore;
}

int main()
{
  Polinomio p;
  p.N = 3;
  p.coeff[0] = 1;
  p.coeff[1] = 2;
  p.coeff[2] = 3;
  float res = ValorePolinomio(p, 10);
  printf("%f\n", res);
}
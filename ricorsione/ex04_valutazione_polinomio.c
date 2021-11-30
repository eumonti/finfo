#include <stdio.h>

// p[]: x^0 x^1 x^2 x^3
float valutaPolinomio(int p[], int n, float x)
{
  if (n == 0)
    return 0.0;
  return p[0] + x * valutaPolinomio(p + 1, n - 1, x);
}

int main()
{
  int coeff[] = {2, 3, 5};
  int n = sizeof(coeff) / sizeof(coeff[0]);
  printf("%f\n", valutaPolinomio(coeff, n, 2));  
}
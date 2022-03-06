#include <stdio.h>

typedef struct
{
  float mantissa;
  int esponente;
} Numero;

float Mantissa(float n)
{
  if (n >= 1.0 && n < 2.0)
    return n - 1.0;
  if (n >= 2.0)
    return Mantissa(n / 2.0);
  return Mantissa(n * 2.0);
}

int Esponente(float n)
{
  if (n >= 1.0 && n < 2.0)
  {
    return 0;
  }
  if (n >= 2.0)
    return 1 + Esponente(n / 2.0);
  return Esponente(n * 2.0) - 1;
}

Numero ConvertiInVirgolaMobile(float n)
{
  Numero res;
  Numero tmp;
  if (n >= 1.0 && n < 2.0)
  {
    res.mantissa = n - 1.0;
    res.esponente = 0;
    return res;
  }
  if (n >= 2.0)
  {
    tmp = ConvertiInVirgolaMobile(n / 2.0);
    res.mantissa = tmp.mantissa;
    res.esponente = 1 + tmp.esponente;
    return res;
  }
  tmp = ConvertiInVirgolaMobile(n * 2.0);
  res.mantissa = tmp.mantissa;
  res.esponente = tmp.esponente - 1;
  return res;
}

int main()
{
  float n = 0.3;
  // printf("M: %f\nE: %d\n", Mantissa(n), Esponente(n));
  Numero res = ConvertiInVirgolaMobile(n);
  printf("M: %f\nE: %d\n", res.mantissa, res.esponente);
}
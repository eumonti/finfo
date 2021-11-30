#include <stdio.h>
#define L 15
typedef enum
{
  falso,
  vero
} Boolean;
int main()
{
  int Sequenza[L] = {0, 1, 0, 1, 2, 3, 2, 1, 4, 67, 100, 101, 102, 103, 104};
  int pmax, pcorr;
  int Lmax, Lcorr;
  int i;
  Boolean finearray = falso;
  Lmax = 1;
  Lcorr = 1;
  pmax = 0;
  pcorr = 0;
  while (!finearray)
  {
    for (i = pcorr + 1;
         i < L && Sequenza[i] > Sequenza[i - 1];
         i++)
      Lcorr++;
    if (Lcorr > Lmax)
    {
      Lmax = Lcorr;
      pmax = pcorr;
    }
    if (i < L)
    {
      pcorr = i;
      Lcorr = 1;
    }
    else
      finearray = vero;
  }
  printf("\n lunghezza massima %d", Lmax);
  printf("\n posizione iniziale %d", pmax);
  return 0;
}
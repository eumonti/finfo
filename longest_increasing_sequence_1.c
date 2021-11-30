#include <stdio.h>
#define L 50
int main()
{
  int A[L] = {1, 2, 5, 2, 1, 2, 3, 4, 5, 6, 7, 8, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int pmax, pcorr;
  int Lmax, Lcorr;
  int i;
  Lmax = 1;
  Lcorr = 1;
  pmax = 0;
  pcorr = 0;
  for (i = 1; i < L; i++)
  {
    if (A[i] > A[i - 1])
    {
      Lcorr++;
      if (Lcorr > Lmax)
      {
        Lmax = Lcorr;
        if (pmax != pcorr)
          pmax = pcorr;
      }
    }
    else
    {
      Lcorr = 1;
      pcorr = i;
    }
  }
  printf("\n lunghezza massima %d", Lmax);
  printf("\n posizione iniziale %d", pmax);
  return 0;
}
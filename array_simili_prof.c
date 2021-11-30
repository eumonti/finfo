#include <stdio.h>

#define N1 20
#define N2 20

int main()
{
  float L1[N1] = {};
  float L2[N2] = {};
  int OK;
  int i, j;
  int ultima;
  OK = 1;
  ultima = -1;
  for (i = 0; i < N1 && OK == 1; i++)
  {
    j = 0;
    while (j < N2 && L2[j] != L1[i])
      j++;
    if (j < N2) /*L2[j]==L1[j]*/
      if (j > ultima)
        ultima = j;
      else
        OK = 0;
  }
}
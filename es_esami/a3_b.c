// Due sequenze A e B di N >= 2 interi non nulli sono SIMILI se i rapporti A[i] / B[i] per tutti gli i
// tra 0 e N-1. Scrivere un sottoprogramma che, ricevendo in ingresso due liste sequenziali di interi, cerca le
// due sottosequenze simili di massima lunghezza (una nella prima lista e una nella seconda lista), restituendo
// una struct contenente la lunghezza massima trovata e i due puntatori ai primi elementi delle due sequenze
// simili.

#include "../liste_dinamiche/lib/linkedlist_int.h"
#include <stdio.h>

#define MAX_LEN 30
// Lista sequenziale
typedef struct
{
  int arr[30];
  int N;
} Sequenza;

struct result
{
  int len;
  int *start1;
  int *start2;
};

struct result fun(Sequenza s1, Sequenza s2)
{
  int i, j;
  int iLocal, jLocal;
  struct result res;
  int tmpLen;

  res.len = 0;
  for (i = 0; i < s1.N - 1; i++)
  {
    for (j = 0; j < s2.N - 1; j++)
    {
      // s1.arr[i] / s2.arr[i] == s2.arr[i + 1] / s2.arr[i + 2] => s1.arr[i]*s2.arr[i+1] == s2.arr[i+1] * s2.arr[i]
      if (s1.arr[i] * s2.arr[j + 1] == s1.arr[i + 1] * s2.arr[j])
      {
        tmpLen = 1;
        iLocal = i;
        jLocal = j;
        while (iLocal < s1.N - 1 && jLocal < s2.N - 1 &&
               s1.arr[iLocal] * s2.arr[jLocal + 1] == s1.arr[iLocal + 1] * s2.arr[jLocal])
        {
          tmpLen++;
          iLocal++;
          jLocal++;
        }
        if (tmpLen > res.len)
        {
          res.len = tmpLen;
          res.start1 = &s1.arr[i];
          res.start2 = &s2.arr[j];
        }
        tmpLen = 0;
      }
    }
  }
  return res;
}

int main()
{
  Sequenza s1, s2;
  s1.N = 4;
  s2.N = 6;
  s1.arr[0] = 1;
  s1.arr[1] = 3;
  s1.arr[2] = 5;
  s1.arr[3] = 6;

  s2.arr[0] = 8;
  s2.arr[1] = 6;
  s2.arr[2] = 10;
  s2.arr[3] = 12;
  s2.arr[4] = 1;
  s2.arr[5] = 3;
  struct result res = fun(s1, s2);
  printf("Length:%d\nStart1:%d\nStart2:%d\n", res.len, *res.start1, *res.start2);
}
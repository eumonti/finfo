/*
Scrivere un programma che, data una stringa A, trovi la più lunga sottosequenza
S periodica di periodo T. Una sottosequenza S è periodica di periodo T se
(i) La sua lunghezza N è >= 2*T
(ii) per tutti gli i tra 0 e N-1 è S[i] == S[i+T]
Il programma deve trovare il massimo periodo T per cui esistano sottosequenze
periodiche e -tra queste- determinare la più lunga.
*/

#include <stdio.h>

int main()
{
  char A[] = "ttorerettorerettorerettoreashdrettavias"; //40
  int len = sizeof(A) / sizeof(A[0]) - 1;
  int T = len / 2; // la lunghezza N della sotto sequenza è >= 2T, quindi T <= N/2. Il valore di partenza è len/2
  int i;
  int currN = 0;
  int maxN = 0;

  while (T > 0)
  {
    for (i = 0; i < T; i++)
    {
      if (A[i] == A[i + T])
      {
        currN += 2;
      }
      else
      {
        if (currN >= 2 * T && currN > maxN) // é una sequenza? è più lunga delle precedenti?
        {
          maxN = currN;
        }
        currN = 0;
      }
    }
    printf("Massimo periodo: %d\nLunghezza sequenza:", T);
  }
}
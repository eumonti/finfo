#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "../liste_dinamiche/lib/linkedlist_int.h"

// Restituisce al chiamante una lista dinamica contenente i numeri primi minori o uguali a N
// disposti in ordine crescente
// NOTA: la fuzione deve essere ricorsiva

int checkPrime(int n)
{
  int i;
  for (i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

// Node *fun(int N)
// {
//   Node *pHead;
//   Node **ppCurr;
//   int i;

//   pHead = NULL;
//   ppCurr = &pHead;
//   for (i = 2; i <= N; i++)
//   {
//     if (checkPrime(i))
//     {
//       *ppCurr = malloc(sizeof(Node));
//       (*ppCurr)->data = i;
//       ppCurr = &((*ppCurr)->next);
//     }
//   }

//   return pHead;
// }

int main()
{
  // Node *result = fun(31);
  // printList(result);
  printf("%d\n", checkPrime(3));
}
// Esercizio A1. Scrivere una procedura ricorsiva che, ricevendo una lista di interi positivi, la modifica
// cancellandone gli elementi il cui valore è un numero primo e la rende disponibile al chiamante.
#include <stdio.h>
#include <stdlib.h>
#include "../liste_dinamiche/lib/linkedlist_int.h"

int checkPrime(int n)
{
  int i;
  for (i = 2; i <= n / 2; i++)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

// Ricorsiva
void cancellaPrimi(Node **pList)
{
  Node *tmp;
  if (*pList == NULL)
    return;
  if (checkPrime((*pList)->data) == 1)
  {
    tmp = *pList;
    *pList = (*pList)->next;
    free(tmp);
    cancellaPrimi(pList);
  }
  else
    cancellaPrimi(&(*pList)->next);
}

int main()
{
  Node *list = getSequence("sequence.txt");
  printList(list);
  cancellaPrimi(&list);
  printList(list);
  // printf("%d\n", checkPrime(17));
}
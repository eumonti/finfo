#include <stdio.h>
#include <stdlib.h>
#include "lib/linkedlist.h"

int checkPrime(int n)
{
  int i;
  for (i = 2; i <= n / 2; i++)
  {
    if(n % i == 0) // Se trovo un numero per cui n è divisibile, n non è primo
      return 0;
  }
  return 1;
}

void deletePrime(Node **pList)
{
  Node *tmp;

  if (*pList == NULL)
    return;

  deletePrime(&((*pList)->next));

  if (checkPrime((*pList)->data))
  {
    tmp = *pList;
    *pList = (*pList)->next;
    free(tmp);
  }
}

int main()
{
  Node *list = getSequence("sequence1.txt");
  deletePrime(&list);
  printList(list);
}
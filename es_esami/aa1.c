#include "../liste_dinamiche/lib/linkedlist_int.h"
#include <stdlib.h>

void CancellaPrimi(Node **pLista)
{
  Node *tmp;
  int i;
  int primo;
  if (*pLista == NULL)
    return;
  i = 2;
  primo = 1;
  while (i * i <= (*pLista)->data && primo)
  {
    if ((*pLista)->data % i == 0)
      primo = 0;
    i++;
  }
  if (!primo)
  {
    CancellaPrimi(&(*pLista)->next);
    return;
  }
  tmp = *pLista;
  *pLista = (*pLista)->next;
  free(tmp);
  CancellaPrimi(pLista);
}

int main()
{
  Node *list = getSequence("sequence.txt");
  printList(list);
  CancellaPrimi(&list);
  printList(list);
}
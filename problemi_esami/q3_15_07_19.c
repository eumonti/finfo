#include "../liste_dinamiche/lib/linkedlist_int.h"
#include <stdlib.h>
#include <stdio.h>

typedef Node *Lista;

void Semplifica(Lista *pL)
{
  Node **pCurr;
  Node *tmp;
  if (*pL == NULL && (*pL)->next == NULL)
    return;

  for (pCurr = pL; (*pCurr) != NULL; pCurr = &(*pCurr)->next)
  {
    if ((*pCurr)->data == (*pL)->data)
    {
      // tmp = *pL;
      // *pL = (*pL)->next;
      // free(tmp);
      // return;
      tmp = (*pL)->next;
      free(*pL);
      *pL = tmp;
      return;
    }
  }
  Semplifica(&(*pL)->next);
}

int main()
{
  Lista L = getSequence("files/sequence.txt");
  Semplifica(&L);
  printList(L);
}
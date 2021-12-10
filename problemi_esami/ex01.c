#include <stdio.h>
#include <stdlib.h>
#include "../liste_dinamiche/lib/linkedlist.h"

void Semplifica(Node **ppHead)
{
  if (*ppHead == NULL)
    return;
  Node *pCurr;
  Semplifica(&((*ppHead)->next));
  for (pCurr = (*ppHead)->next; pCurr != NULL; pCurr = pCurr->next)
  {
    if ((*ppHead)->data == pCurr->data)
    {
      // Delete pHead
      Node *pNextNode = *ppHead;
      *ppHead = ((*ppHead)->next);
      free(pNextNode);
    }
  }
}

int main()
{
  Node *list = getSequence("files/sequence.txt");
  Semplifica(&list);
  printList(list);
}
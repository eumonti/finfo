#include <stdlib.h>
#include "lib/linkedlist_char.h"

Node *commonText(Node *textA, Node *textB)
{
  Node *pCurrA, *pCurrB;
  Node *pLocalCurrA, *pLocalCurrB;
  Node *pCommonText;
  Node *pNewListHead, **ppNewListCurr;
  int commonTextLen, localCommonTextLen;
  commonTextLen = -1;
  localCommonTextLen = 0;
  for (pCurrA = textA; pCurrA != NULL; pCurrA = pCurrA->next)
  {
    for (pCurrB = textB; pCurrB != NULL; pCurrB = pCurrB->next)
    {
      if (pCurrA->data == pCurrB->data)
      {
        pLocalCurrA = pCurrA;
        pLocalCurrB = pCurrB;
        while (pLocalCurrA != NULL &&
               pLocalCurrB != NULL &&
               pLocalCurrA->data == pLocalCurrB->data)
        {
          localCommonTextLen++;
          pLocalCurrA = pLocalCurrA->next;
          pLocalCurrB = pLocalCurrB->next;
        }
        if (localCommonTextLen > commonTextLen)
        {
          commonTextLen = localCommonTextLen;
          pCommonText = pCurrA;
        }
        localCommonTextLen = 0;
      }
    }
  }

  // Make new linked list and return it
  ppNewListCurr = &pNewListHead;
  for (int i = 0; i < commonTextLen; i++)
  {
    *ppNewListCurr = malloc(sizeof(Node));
    (*ppNewListCurr)->data = pCommonText->data;
    ppNewListCurr = &((*ppNewListCurr)->next);
    pCommonText = pCommonText->next;
  }
  *ppNewListCurr = NULL;
  return pNewListHead;
}

int main()
{
  Node *textA = getSequence("sequence1.txt");
  Node *textB = getSequence("sequence2.txt");
  printList(textA);
  printList(textB);
  printList(commonText(textA, textB));
}
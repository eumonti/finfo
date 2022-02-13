#include "../liste_dinamiche/lib/linkedlist_int.h"
#include <stdlib.h>

typedef Node *Lista;

void SdoppiaLista(Lista L1, Lista *pL2) // L1 dispari, L2 pari
{                                       // L1 è sempre nodo dispari
  if (L1 == NULL || L1->next == NULL)
  {
    *pL2 = NULL;
    return;
  }
  *pL2 = L1->next;
  L1->next = L1->next->next;
  SdoppiaLista(L1->next, &(*pL2)->next);
}

void Concatena(Lista L1, Lista *pL2)
{
  Node *curr1, *curr2;
  Node *tmpNext1, *tmpNext2;

  curr1 = L1;
  curr2 = *pL2;
  while (curr1 != NULL && curr2 != NULL)
  {
    tmpNext1 = curr1->next;
    tmpNext2 = curr2->next;
    curr1->next = curr2;
    curr2->next = tmpNext1;
    curr1 = tmpNext1;
    curr2 = tmpNext2;
  }
  *pL2 = NULL;
}

void ConcatenaRic(Lista L1, Lista L2)
{
  Node *tmpNext1, *tmpNext2;

  if (L1 == NULL || L2 == NULL)
    return;

  tmpNext1 = L1->next;
  tmpNext2 = L2->next;
  L2->next = L1->next;
  L1->next = L2;
  ConcatenaRic(tmpNext1, tmpNext2);
}

void ConcatenaCaglioti(Lista *pL1, Lista L2)
{
  Node *curs;
  if (*pL1 == NULL)
    return;
  curs = *pL1;
  while (curs->next != NULL)
    curs = curs->next;
  curs->next = L2;
}

int main()
{
  Lista L1 = getSequence("sequence.txt");
  Lista L2;
  SdoppiaLista(L1, &L2);
  // ConcatenaRic(L1, L2);
  ConcatenaCagliotiMerda(&L1, L2);
  printList(L1);
  printList(L2);
}
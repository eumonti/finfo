#include "../liste_dinamiche/lib/linkedlist_int.h"
#include <stdlib.h>
#include <stdio.h>

typedef Node *Lista;

int stessoOrdine(Lista L1, Lista L2)
{
  Node *curs1, *curs2, *curs3;
  Node *last;

  last = NULL;
  for (curs1 = L1; curs1 != NULL; curs1 = curs1->next)
  {
    curs2 = L2;
    while (curs2 != NULL && curs2->data != curs1->data)
      curs2 = curs2->next;

    if (curs2 != NULL)
    {
      if (last != NULL)
      {
        curs3 = last;
        while (curs3 != NULL && curs3 != curs2)
          curs3 = curs3->next;
        if (curs3 == NULL)
          return 0;
      }
      last = curs2;
    }
  }
  return 1;
}

int stessoOrdine2(Lista L1, Lista L2)
{
  Node *curs1, *curs2;
  Node *last;
  int result;

  last = NULL;
  for (curs1 = L1; curs1 != NULL; curs1 = curs1->next)
  {
    result = 0;
    curs2 = L2;
    while (curs2 != NULL && curs1->data != curs2->data)
    {
      if (curs2 == last)
        result = 1;
      curs2 = curs2->next;
    }
    if (last == NULL)
      result = 1;
    if (result == 0)
      return 0;
    if (curs2 != NULL)
    {
      last = curs2;
    }
  }
  return 1;
}
// curs2 = L2;
// while (curs2 != NULL && curs2->data != curs1->data)
//   curs2 = curs2->next;

// if (curs1->data == curs2->data)
// {
//   curs2 = last;
//   while (curs2 != NULL && curs2->data != curs1->data)
//     curs2 = curs2->next;
//   if (curs2 == NULL)
//     return 0;
// }
// }

int main()
{
  Lista L1 = getSequence("sequence.txt");
  Lista L2 = getSequence("sequence2.txt");
  printf("%d\n", stessoOrdine2(L1, L2));
}
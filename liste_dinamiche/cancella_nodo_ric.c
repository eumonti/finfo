#include "lib/linkedlist_int.h"
#include <stdlib.h>

Node *delRec(Node *list, int n)
{
  Node *next;
  if (list == NULL)
    return list;
  if (list->data == n)
  {
    next = list->next;
    free(list);
    return next;
  }
  list->next = delRec(list->next, n);
  return list;
}

void del(Node **pList, int n)
{
  Node *tmp;
  while (*pList != NULL)
  {
    if ((*pList)->data == n)
    {
      tmp = *pList;
      *pList = (*pList)->next;
      free(tmp);
    }
    pList = &(*pList)->next;
  }
}

int main()
{
  Node *list = getSequence("sequence1.txt");
  del(&list, 10);
  printList(list);
}
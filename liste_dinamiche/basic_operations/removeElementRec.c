#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist_int.h"

Node *removeRec(Node *list, int n)
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
  list->next = removeRec(list->next, n);
  return list;
}

int main()
{
  Node *list = getSequence("sequence.txt");
  list = removeRec(list, 10);
  printList(list);
}
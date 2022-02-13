#include "lib/linkedlist_int.h"
#include <stdlib.h>

Node *insInOrdRic(Node *list, Node *new)
{
  if (list == NULL || new->data < list->data)
  {
    new->next = list;
    return new;
  }
  list->next = insInOrdRic(list->next, new);
  return list;
}

int main()
{
  Node *list = getSequence("sequence1.txt");
  Node *new = newNode(11);
  list = insInOrdRic(list, new);
  printList(list);
}
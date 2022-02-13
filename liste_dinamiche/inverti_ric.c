#include "lib/linkedlist_int.h"
#include <stdlib.h>

Node *reverse(Node *list)
{
  Node *prec;
  if (list == NULL || list->next == NULL)
    return list;
  prec = reverse(list->next);
  list->next->next = list;
  list->next = NULL;
  return prec;
}

int main()
{
  Node *list = getSequence("sequence1.txt");
  printList(list);
  list = reverse(list);
  printList(list);
}
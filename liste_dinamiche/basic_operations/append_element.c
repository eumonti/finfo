#include <stdio.h>
#include "../lib/linkedlist.h"

void recursiveAppend(Node **list, int data)
{
  if (*list == NULL)
  {
    *list = newNode(data);
    return;
  }
  if ((*list)->next == NULL)
  {
    Node *lastNode = newNode(data);
    (*list)->next = lastNode;
    return;
  }
  recursiveAppend(&(*list)->next, data);
}

int main()
{
  Node *list = getSequence("../sequence.txt");
  recursiveAppend(&list, 27);
  printList(list);
  freeList(list);
}
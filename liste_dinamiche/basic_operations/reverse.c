#include <stdio.h>
#include "../lib/linkedlist.h"

// 2 -> 3 -> 4 -> 5
void reverseList(Node **list)
{
  Node *curr = *list;
  Node *last = NULL;
  Node *next;
  while (curr != NULL)
  {
    next = curr->next;
    curr->next = last;
    last = curr;
    curr = next;
  }
  *list = last;
}

void reverseListRec(Node **pList)
{
  Node *temp;
  if ((*pList)->next == NULL)
  {
    return;
  }
  temp = (*pList)->next;
  reverseListRec(&temp);
  (*pList)->next->next = *pList;
}

int main()
{
  Node *list = getSequence("../sequence.txt");
  // reverseList(&list);
  reverseListRec(&list);
  printList(list);
  freeList(list);
}
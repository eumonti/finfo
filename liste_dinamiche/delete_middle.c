#include <stdio.h>
#include <stdlib.h>
#include "lib/linkedlist.h"

void deleteMiddle(Node **pList)
{
  Node *tmp;
  Node *slow, *fast;
  int nodeCount;
  if (*pList == NULL)
    return;
  if ((*pList)->next == NULL)
  {
    free(*pList);
    *pList = NULL;
    return;
  }
  if (((*pList)->next->next) == NULL)
  {
    tmp = *pList;
    *pList = (*pList)->next;
    free(tmp);
    return;
  }

  fast = *pList;
  slow = *pList;
  nodeCount = 0;

  while (fast != NULL)
  {
    if (nodeCount > 2 && nodeCount % 2 == 0)
    {
      printf("Incrementing slow\n");
      slow = slow->next;
    }
    nodeCount++;

    fast = fast->next;
  }

  tmp = slow->next;
  slow->next = slow->next->next;
  free(tmp);
}

int main()
{
  Node *list = getSequence("sequence1.txt");
  printList(list);
  deleteMiddle(&list);
  printList(list);
}
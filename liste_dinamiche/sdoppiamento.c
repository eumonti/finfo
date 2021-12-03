#include <stdio.h>
#include "lib/linkedlist.h"

void handleAdd(Node **pList, Node **pCurr, int data)
{
  if (*pList == NULL) // Add it as first element
  {
    *pList = newNode(data);
    *pCurr = *pList;
  }
  else
  {
    (*pCurr)->next = newNode(data);
    *pCurr = (*pCurr)->next;
  }
}

void sdoppia(Node *list, Node **pEvenList, Node **pOddList)
{
  int nodeCount = 1;
  Node *curr;
  Node *currEven, *currOdd;

  *pEvenList = NULL;
  *pOddList = NULL;

  for (curr = list; curr != NULL; (curr = curr->next, nodeCount++)) // Iterate trough list, incrementing nodeCount each time
  {
    if (nodeCount % 2 == 0) // Position is even, add to evenList
      handleAdd(pEvenList, &currEven, curr->data);
    else // Position is odd, add to oddList
      handleAdd(pOddList, &currOdd, curr->data);
  }
}
int main()
{
  Node *list = getSequence("sequence1.txt");
  Node *evenList, *oddList;
  sdoppia(list, &evenList, &oddList);
  printList(list);
  printList(evenList);
  printList(oddList);
}
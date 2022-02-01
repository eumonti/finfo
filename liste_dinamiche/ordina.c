#include <stdio.h>
#include "lib/linkedlist_int.h"

// prev->curr->next->(next->next)
// Swap curr with next
// prev->next->curr->(next->next)

// Bubble sort

// 20->12->13->8->4->6->2->3->1->NULL

// Shitty way
void ordina(Node **pList)
{
  Node *curr1, *curr2;
  Node *prev, *next;
  Node *endNode;
  endNode = NULL;
  for (curr1 = *pList; curr1 != NULL; curr1 = curr1->next)
  {
    prev = NULL;
    curr2 = *pList;
    while (curr2->next != endNode)
    {
      if (curr2->data > curr2->next->data)
      {
        if (prev == NULL) // First node
        {
          next = curr2->next;
          curr2->next = next->next;
          next->next = curr2;
          prev = next;
          *pList = next;
        }
        else
        {
          next = curr2->next;
          prev->next = next;
          curr2->next = next->next;
          next->next = curr2;
          prev = next;
        }
      }
      else
      {
        prev = curr2;
        curr2 = curr2->next;
      }
    }
    endNode = curr2;
  }
}

// Better way
void ordina2(Node **pList)
{
  Node *curr1, **pCurr2;
  Node *next;
  Node *endNode;
  endNode = NULL;
  for (curr1 = *pList; curr1 != NULL; curr1 = curr1->next)
  {
    pCurr2 = pList;
    while ((*pCurr2)->next != endNode)
    {
      if ((*pCurr2)->data > (*pCurr2)->next->data)
      {
        next = (*pCurr2)->next;
        (*pCurr2)->next = next->next;
        next->next = (*pCurr2);
        *pCurr2 = next;
      }
      else
      {
        pCurr2 = &(*pCurr2)->next;
      }
    }
    endNode = *pCurr2;
  }
}

int main()
{
  Node *list = getSequence("sequence2.txt");
  ordina2(&list);
  printList(list);
}
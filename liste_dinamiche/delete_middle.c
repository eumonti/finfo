#include <stdio.h>
#include <stdlib.h>
#include "lib/linkedlist.h"

typedef enum
{
  false,
  true
} bool;

void deleteMiddleOld(Node **pList)
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

// void deleteMiddle2(Node **pList)
// {
// Node **pSlow, *fast;
// int moveSlow = 0;
// if (*pList == NULL)
//   return;

// fast = (*pList)->next;
// *pSlow = pList;

// while (fast != NULL)
// {
//   if (moveSlow)
//   {
//     printf("Incrementing slow\n");
//     *pSlow = (*pSlow)->next;
//   }
//   moveSlow = !moveSlow;

//   fast = fast->next;
// }

// tmp = pSlow->next;
// pSlow->next = pSlow->next->next;
// free(tmp);
// }

void deleteMiddle(Node **pList)
{
  Node *pCurr, *pNodeToDel;
  Node *pTmp;
  bool moveSlow = false;

  if (*pList = NULL)
    return;

  pCurr = (*pList)->next;
  pNodeToDel = *pList;
  while (pCurr != NULL)
  {
    if (moveSlow)
      pNodeToDel = pNodeToDel->next;

    moveSlow = !moveSlow;
    pCurr = pCurr->next;
  }

  // Delete node
  // pTmp = pNodeToDel->next;
  // pNodeToDel->next = pNodeToDel->next->next;
  pTmp = pNodeToDel;
  pNodeToDel = pNodeToDel->next;
  free(pTmp);
}

void deleteMiddleFontana(Node **pList)
{
  Node *curr;

  Node **pNodeToDel;
  Node *nodeToDel;

  bool moveSlow;

  if (NULL == *pList)
    return;

  curr = (*pList)->next;
  pNodeToDel = pList;

  moveSlow = false;

  while (NULL != curr)
  {
    if (moveSlow)
      pNodeToDel = &((*pNodeToDel)->next);

    moveSlow = !moveSlow;
    curr = curr->next;
  }

  /* eliminazione dell'elemento centrale della lista */
  nodeToDel = *pNodeToDel;
  *pNodeToDel = nodeToDel->next;
  free(nodeToDel);
}
int main()
{
  Node *list = getSequence("sequence1.txt");
  printList(list);
  // deleteMiddle2(&list);
  // deleteMiddleFontana(&list);
  deleteMiddleFontana(&list);
  printList(list);
}
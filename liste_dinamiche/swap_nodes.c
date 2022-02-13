#include <stdlib.h>
#include "lib/linkedlist_int.h"

void swapNodes(Node **pList, int a, int b)
{
  int i;
  Node **pNodeA, **pNodeB;
  Node *tmp;
  i = 0;
  pNodeA = pList;
  while (i < a)
  {
    pNodeA = &(*pNodeA)->next;
    i++;
  }
  i = 0;
  pNodeB = pList;
  while (i < b)
  {
    pNodeB = &(*pNodeB)->next;
    i++;
  }

  tmp = (*pNodeA)->next;
  (*pNodeA)->next = (*pNodeB)->next;
  (*pNodeB)->next = tmp;
  tmp = *pNodeB;
  *pNodeB = *pNodeA;
  *pNodeA = tmp;
  // next = nodeA->next;
  // nodeA->next = nodeB->next;
  // nodeB->next = next;
  // if (prevA != NULL)
  // {
  //   prevA->next = nodeB;
  // }
  // else
  // {
  //   *pList = nodeB;
  // }
  // if (prevB != NULL)
  // {
  //   prevB->next = nodeA;
  // }
  // else
  // {
  //   *pList = nodeA;
  // }
}

Node *leetCode(Node *head, int k)
{
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

  Node *curr;
  Node *nodeX;
  Node *nodeY;
  Node *prevX, *prevY;
  Node *tmp;
  prevX = NULL;
  prevY = NULL;
  int len;
  int i;
  len = 0;
  for (curr = head; curr != NULL; curr = curr->next)
    len++;
  if (len < 2)
    return head;
  nodeX = head;
  for (i = 0; i < k; i++)
  {
    prevX = nodeX;
    nodeX = nodeX->next;
  }
  nodeY = head;
  for (i = 0; i < len - k; i++)
  {
    prevY = nodeY;
    nodeY = nodeY->next;
  }

  tmp = nodeX->next;
  nodeX->next = nodeY->next;
  nodeY->next = tmp;
  if (prevX == NULL)
    return nodeX;
  else
    prevX->next = nodeY;

  prevY->next = nodeX;
  return head;
}

int main()
{
  Node *list = getSequence("sequence1.txt");
  printList(list);
  list = leetCode(NULL, 2);
  printList(list);
}
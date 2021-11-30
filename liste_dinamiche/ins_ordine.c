#include <stdio.h>
#include "lib/linkedlist.h"

void insOrdine(Node **list, int data)
{
  Node *curr;
  Node *new = newNode(data);
  curr = *list;
  if (*list == NULL || (*list)->next == NULL || (*list)->data > data)
  {
    new->next = curr;
    *list = new;
    return;
  }
  while (curr->next != NULL && curr->next->data < data)
  {
    curr = curr->next;
  }
  new->next = curr->next;
  curr->next = new;
}

void insOrdineRicorsiva(Node **list, int data)
{
  Node *new = newNode(data);
  if ((*list)->data > data)
  {
    new->next = *list;
    *list = new;
    return;
  }
  if ((*list)->next->data > data)
  {
    new->next = (*list)->next;
    (*list)->next = new;
    return;
  }
  insOrdineRicorsiva(&((*list)->next), data);
}

int main()
{
  Node *list = getSequence("sequence.txt");
  // printList(list);
  // insOrdineRicorsiva(&list, 0);
  printf("%p\n", list);
  printList(list);
  freeList(list);
}
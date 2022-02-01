#include <stdio.h>
#include "lib/linkedlist_int.h"

int stessePosizioni(Node *lista1, Node *lista2)
{
  Node *p1, *p2;
  Node *pos2;
  p1 = lista1;
  p2 = lista2;
  pos2 = lista2;

  while (p1 != NULL)
  {
    while (p2 != NULL)
    {
      if (p2 != pos2 && p1->data == p2->data)
      {
        return 0;
      }
      p2 = p2->next;
    }
    p1 = p1->next;
    if (pos2 = !NULL)
      pos2 = pos2->next;
  }
  return 1;
}

int main()
{
  Node *lista1 = getSequence("sequence1.txt");
  Node *lista2 = getSequence("sequence2.txt");
  stessePosizioni(lista1, lista2) ? printf("Tutti gli elementi sono in posizioni diverse.\n") : printf("Elementi uguali in posizioni diverse.\n");
}
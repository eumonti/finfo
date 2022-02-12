#include <stdio.h>
#include <stdlib.h>
#include "../liste_dinamiche/lib/linkedlist_int.h"

struct result
{
  int len;
  Node *start1;
  Node *start2;
};

struct result CercaSimili(Node *L1, Node *L2)
{
  Node *curs1, *curs2, *succ1, *succ2, *loc1, *loc2;
  int cont;
  int max;
  struct result ris;
  int A, B;
  max = 0;
  loc1 = NULL;
  loc2 = NULL;
  curs1 = L1;
  while (curs1 != NULL)
  {
    curs2 = L2;
    cont = 0;
    while (curs2 != NULL)
    {
      A = curs1->data;
      B = curs2->data;
      succ1 = curs1->next;
      succ2 = curs2->next;
      cont = 1;
      while (succ1 != NULL && succ2 != NULL && succ1->data * B == succ2->data * A)
      {
        cont++;
        succ1 = succ1->next;
        succ2 = succ2->next;
      }
      if (cont > max)
      {
        max = cont;
        loc1 = curs1;
        loc2 = curs2;
      }
      cont = 0;
      curs2 = curs2->next;
    }
    curs1 = curs1->next;
  }
  ris.start1 = loc1;
  ris.start2 = loc2;
  ris.len = max;
  return (ris);
}

struct result fun(Node *l1, Node *l2)
{
  Node *curr1, *curr2;
  Node *curr1Local, *curr2Local;
  int tmpLen;

  struct result res;
  tmpLen = 0;
  res.len = 0;
  for (curr1 = l1; curr1 != NULL; curr1 = curr1->next)
  {
    for (curr2 = l2; curr2 != NULL; curr2 = curr2->next)
    {
      curr1Local = curr1;
      curr2Local = curr2;
      tmpLen = 1;
      while (curr1Local->next != NULL && curr2Local->next != NULL &&
             curr1Local->data * curr2Local->next->data == curr2Local->data * curr1Local->next->data)
      {
        tmpLen++;
        curr1Local = curr1Local->next;
        curr2Local = curr2Local->next;
      }
      if (tmpLen > res.len)
      {
        res.len = tmpLen;
        res.start1 = curr1;
        res.start2 = curr2;
      }
      tmpLen = 0;
    }
  }
  return res;
}

int main()
{
  Node *list1 = getSequence("sequence.txt");
  Node *list2 = getSequence("sequence2.txt");
  struct result res = fun(list1, list2);
  printf("Length: %d\nStart1: %d\nStart2: %d\n", res.len, (res.start1)->data, (res.start2)->data);
}
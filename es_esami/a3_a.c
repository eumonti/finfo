// Date due liste dinamiche di interi si vuole determinare la più lunga sottosequenza comune
// alle due liste. Scrivere un sottoprogramma che, ricevendo in ingresso due liste dinamiche di interi, cerca la
// più lunga sequenza comune alle due liste; restituisce una struct contenente
// (i) la lunghezza della più lunga sequenza comune
// (ii) una coppia di puntatori, uno per ciascuna lista, al nodo di inizio della sequenza comune. **
#include "../liste_dinamiche/lib/linkedlist_int.h"
#include <stdio.h>

struct result
{
  int len;
  Node *start1;
  Node *start2;
};

struct result fun(Node *l1, Node *l2)
{
  struct result res;
  struct result tmpRes;
  Node *curr1, *curr2;

  res.len = 0;
  for (curr1 = l1; curr1 != NULL; curr1 = curr1->next)
  {
    for (curr2 = l2; curr2 != NULL; curr2 = curr2->next)
    {
      if (curr1->data == curr2->data)
      {
        tmpRes.start1 = curr1;
        tmpRes.start2 = curr2;

        tmpRes.len = 0;

        while (curr1 != NULL && curr2 != NULL && curr1->data == curr2->data)
        {
          curr1 = curr1->next;
          curr2 = curr2->next;
          tmpRes.len++;
        }
        if (tmpRes.len > res.len)
        {
          res.len = tmpRes.len;
          res.start1 = tmpRes.start1;
          res.start2 = tmpRes.start2;
        }
        tmpRes.len = 0;
        curr1 = tmpRes.start1;
        curr2 = tmpRes.start2;
      }
    }
  }
  return res;
}

// This thing shits the bed if l1 ends before l2
/* struct result fun(Node *l1, Node *l2)
{
  struct result res;
  struct result tmpRes;
  Node *curr1, *curr2;

  res.len = 0;
  tmpRes.len = 0;
  curr1 = l1;
  while (curr1 != NULL)
  {
    curr2 = l2;
    while (curr2 != NULL)
    {
      if (curr1 != NULL && curr1->data == curr2->data)
      {
        if (tmpRes.len == 0)
        {
          tmpRes.start1 = curr1;
          tmpRes.start2 = curr2;
        }
        tmpRes.len++;
        curr1 = curr1->next;
        curr2 = curr2->next;
      }
      else
      {
        if (tmpRes.len > res.len)
        {
          res.start1 = tmpRes.start1;
          res.start2 = tmpRes.start2;
          res.len = tmpRes.len;
        }
        tmpRes.len = 0;
        curr2 = curr2->next;
      }
    }
    curr1 = curr1->next;
  }
  return res;
}
*/
int main()
{
  Node *list1 = getSequence("sequence.txt");
  Node *list2 = getSequence("sequence2.txt");
  struct result res = fun(list1, list2);
  printf("Length: %d\nStart1: %d\nStart2: %d\n", res.len, res.start1->data, res.start2->data);
}
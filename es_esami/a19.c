#include "../liste_dinamiche/lib/linkedlist_int.h"
#include <stdlib.h>

typedef Node Nodo;
typedef Nodo *Lista;

Lista fun_a(Lista L)
{
  Lista res;
  Nodo *curr;
  Nodo **pCurrRes;

  pCurrRes = &res;
  curr = L;
  while (curr != NULL)
  {
    if (curr->next == NULL || curr->data > curr->next->data)
    {
      *pCurrRes = malloc(sizeof(Nodo));
      (*pCurrRes)->data = curr->data;
      pCurrRes = &(*pCurrRes)->next;
    }
    curr = curr->next;
  }
  *pCurrRes = NULL;
  return res;
}

Lista fun_b(Lista L)
{
  Nodo *curr, *prec;

  prec = NULL;
  curr = L;
  while (curr->next != NULL)
  {
    if (curr->data <= curr->next->data)
    {
      // Elimina curr
      if (prec == NULL) // Primo
      {
        L = curr->next;
        free(curr);
        curr = L;
      }
      else
      {
        prec->next = curr->next;
        free(curr);
        curr = prec->next;
      }
    }
    else
    {
      prec = curr;
      curr = curr->next;
    }
  }
  return L;
}

void fun_c(Lista *pL)
{
  Node *tmp;
  if (*pL == NULL || (*pL)->next == NULL)
    return;

  if ((*pL)->data <= (*pL)->next->data)
  {
    tmp = *pL;
    *pL = (*pL)->next;
    free(tmp);
    fun_c(pL);
    return;
  }
  fun_c(&(*pL)->next);
}

void fun_c1(Lista *pL)
{
  Node *tmp;
  int elimina;
  if (*pL == NULL || (*pL)->next == NULL)
    return;
  elimina = 0;
  if ((*pL)->data <= (*pL)->next->data)
    elimina = 1;
  fun_c1(&(*pL)->next);

  if (elimina)
  {
    tmp = *pL;
    *pL = (*pL)->next;
    free(tmp);
    return;
  }
}

void SoloMaggioriDelSuccRic(Lista *pL)
{
  Nodo *punt;
  if (*pL == NULL || (*pL)->next == NULL)
    return;
  if ((*pL)->data < (*pL)->next->data)
  {
    punt = *pL;
    *pL = (*pL)->next;
    free(punt);
    SoloMaggioriDelSuccRic(pL);
    return;
  }
  SoloMaggioriDelSuccRic(&((*pL)->next));
}

Lista MaggioriDelSuccModifica(Lista L)
{
  Nodo *prec, *curr;
  if (L == NULL || L->next == NULL)
    return L;
  curr = L;
  while (curr->next != NULL)
  {
    if (curr->data <= curr->next->data)
    {
      if (curr == L)
      {
        L = L->next;
        free(curr);
        curr = L;
      }
      else
      {
        prec->next = curr->next;
        free(curr);
        curr = prec->next;
      }
    }
    else
    {
      prec = curr;
      curr = curr->next;
    }
  }
  return L;
}

int main()
{
  Lista L = getSequence("sequence.txt");
  Lista res = fun_b(L);
  printList(res);

  Lista L4 = getSequence("sequence.txt");
  Lista res2 = MaggioriDelSuccModifica(L4);
  printList(res2);

  Lista L2 = getSequence("sequence.txt");
  SoloMaggioriDelSuccRic(&L2);
  printList(L2);

  Lista L3 = getSequence("sequence.txt");
  fun_c1(&L3);
  printList(L3);
}
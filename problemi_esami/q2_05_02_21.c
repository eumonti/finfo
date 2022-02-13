#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../liste_dinamiche/lib/linkedlist_int.h"

// Restituisce al chiamante una lista dinamica contenente i numeri primi minori o uguali a N
// disposti in ordine crescente
// NOTA: la fuzione deve essere ricorsiva

int checkPrime(int n)
{
  int i;
  for (i = 2; i * i <= n; i++) // Verifiche di divisibilità per i tra 2 e sqrt(n)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

// Node *makePrimesList(int N)
// {
//   Node *new;
//   Node *l;
//   Node *curr;

//   if (N == 2)
//   {
//     l = malloc(sizeof(Node));
//     l->data = N;
//     l->next = NULL;
//     return l;
//   }
//   l = makePrimesList(N - 1);

//   if (checkPrime(N))
//   {
//     curr = l;
//     while (curr->next != NULL)
//       curr = curr->next;
//     new = malloc(sizeof(Node));
//     new->data = N;
//     new->next = NULL;
//     curr->next = new;
//   }
//   return l;
// }
typedef Node *Lista;
typedef Node Nodo;

Lista PrimiCaglioti(int n)
{
  Lista L;
  Nodo *punt, *prec;

  if (n < 2)
    return NULL;
  L = PrimiCaglioti(n - 1);
  prec = NULL;
  punt = L;
  while (punt != NULL && (punt->data) * (punt->data) < n && n % (punt->data) != 0)
  {
    prec = punt;
    punt = punt->next;
  }
  if (punt == NULL || n % (punt->data) != 0)
  {
    while (punt != NULL)
    {
      prec = punt;
      punt = punt->next;
    }
    if (prec == NULL)
    {
      L = malloc(sizeof(Nodo));
      L->data = n;
      L->next = NULL;
    }
    else
    {
      prec->next = malloc(sizeof(Nodo));
      prec->next->data = n;
      prec->next->next = NULL;
    }
  }
  return L;
}

Node *listaPrimi(int n)
{
  Node *list;
  Node *new;
  Node *curr;
  int i;

  if (n < 2)
    return NULL;
  if (n == 2)
  {
    list = malloc(sizeof(Node));
    list->data = n;
    list->next = NULL;
    return list;
  }

  list = listaPrimi(n - 1);

  i = 2;
  while (i * i <= n && n % i != 0)
    i++;
  if (i * i >= n)
  {
    new = malloc(sizeof(Node));
    new->data = n;
    new->next = NULL;
    curr = list;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = new;
  }
  return list;
}

Node *listaPrimi2(int n, Node **pLastEl)
{
  Node *list;
  Node *new;
  int i;

  if (n < 2)
    return NULL;
  if (n == 2)
  {
    list = malloc(sizeof(Node));
    list->data = n;
    list->next = NULL;
    *pLastEl = list;
    return list;
  }

  list = listaPrimi2(n - 1, pLastEl);
  i = 2;
  while (i * i <= n && n % i != 0)
    i++;
  if (i * i >= n)
  {
    new = malloc(sizeof(Node));
    new->data = n;
    new->next = NULL;
    (*pLastEl)->next = new;
    *pLastEl = new;
  }
  return list;
}

Node *listaPrimi3(int n, Node **pHead)
{
  Node *list;
  if (n < 2)
    return NULL;
  if (n == 2)
  {
    *pHead = malloc(sizeof(Node));
    (*pHead)->data = n;
    (*pHead)->next = NULL;
    return *pHead;
  }

  list = listaPrimi3(n - 1, pHead);

  if (checkPrime(n))
  {
    list->next = malloc(sizeof(Node));
    list->next->data = n;
    list->next->next = NULL;
    return list->next;
  }
  return list;
}

Lista listaPrimi4(int n)
{
  Lista l;
  Nodo *new, *curr;

  if (n < 2)
    return NULL;
  if (n == 2)
  {
    new = malloc(sizeof(Node));
    new->data = n;
    new->next = NULL;
    return new;
  }
  l = listaPrimi4(n - 1);
  curr = l;
  while (curr->next != NULL && (curr->data * curr->data) <= n && n % curr->data != 0)
    curr = curr->next;

  if (n % curr->data == 0)
    return l;

  while (curr->next != NULL)
    curr = curr->next;

  new = malloc(sizeof(Node));
  new->data = n;
  new->next = NULL;
  curr->next = new;
  return l;
}

Node *ugo2(int n)
{
  Node *list;
  listaPrimi3(n, &list);
  return list;
}

Node *ugo(int n)
{
  Node *result;
  result = listaPrimi2(n, &result);
  return result;
}

// Node *fun(int N)
// {
//   Node *pHead;
//   Node **ppCurr;
//   int i;

//   pHead = NULL;
//   ppCurr = &pHead;
//   for (i = 2; i <= N; i++)
//   {
//     if (checkPrime(i))
//     {
//       *ppCurr = malloc(sizeof(Node));
//       (*ppCurr)->data = i;
//       ppCurr = &((*ppCurr)->next);
//     }
//   }

//   return pHead;
// }

int main()
{
  Node *result;
  // result = ugo2(31);
  // result = PrimiCaglioti(31);
  result = listaPrimi4(31);
  // result = ugo(31);
  // result = listaPrimi2(31, &result);
  printList(result);
}
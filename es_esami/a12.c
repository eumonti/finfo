#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 20

typedef char Parola[MAX_LEN];

typedef struct nodo
{
  char ch;
  int n;
  struct nodo *next;
} Nodo;

typedef Nodo *ListaOccorrenze;

void fun(Parola p, ListaOccorrenze *pLista)
{
  Nodo **pCurr;

  if (*p == '\0')
    return;

  pCurr = pLista;
  while (*pCurr != NULL && (*pCurr)->ch != *p)
    pCurr = &(*pCurr)->next;

  if (*pCurr == NULL)
  {
    *pCurr = malloc(sizeof(Nodo));
    (*pCurr)->next = NULL;
    (*pCurr)->ch = *p;
    (*pCurr)->n = 1;
  }
  else // Trovato carattere
  {
    (*pCurr)->n++;
  }
  fun(p + 1, pLista);
}

void fun2(Parola p, ListaOccorrenze *pLista)
{
  Nodo **pCurr;

  int trovato = 0;

  if (*p == '\0')
    return;

  pCurr = pLista;
  while (*pCurr != NULL && !trovato)
  {
    if ((*pCurr)->ch == *p)
      trovato = 1;
    else
      pCurr = &(*pCurr)->next;
  }

  if (!trovato)
  {
    *pCurr = malloc(sizeof(Nodo));
    (*pCurr)->next = NULL;
    (*pCurr)->ch = *p;
    (*pCurr)->n = 1;
  }
  else // Trovato carattere
  {
    (*pCurr)->n++;
  }
  fun2(p + 1, pLista);
}

void occorrenzeAlfabetica(Parola p, ListaOccorrenze *pLista)
{
  Nodo **pCurr;
  Nodo *tmp;
  int trovato = 0;

  if (*p == '\0')
    return;

  pCurr = pLista;
  while (*pCurr != NULL && (*pCurr)->ch <= *p && !trovato)
  {
    if ((*pCurr)->ch == *p)
      trovato = 1;
    else
      pCurr = &(*pCurr)->next;
  }

  if (trovato)
  {
    (*pCurr)->n++;
  }
  else
  {
    if (*pCurr != NULL)
      tmp = *pCurr;
    else
      tmp = NULL;
    *pCurr = malloc(sizeof(Nodo));
    (*pCurr)->next = tmp;
    (*pCurr)->ch = *p;
    (*pCurr)->n = 1;
  }

  occorrenzeAlfabetica(p + 1, pLista);
}

void fun2Inversa(Parola p, ListaOccorrenze *pLista)
{
  Nodo **pCurr;

  int trovato = 0;

  if (*p == '\0')
    return;

  fun2Inversa(p + 1, pLista);
  pCurr = pLista;
  while (*pCurr != NULL && !trovato)
  {
    if ((*pCurr)->ch == *p)
      trovato = 1;
    else
      pCurr = &(*pCurr)->next;
  }

  if (trovato)
  {
    (*pCurr)->n++;
  }
  else // Trovato carattere
  {
    *pCurr = malloc(sizeof(Nodo));
    (*pCurr)->next = NULL;
    (*pCurr)->ch = *p;
    (*pCurr)->n = 1;
  }
}

int main()
{
  Parola p = "ordini";
  ListaOccorrenze lista = NULL;
  // fun2Inversa(p, &lista);
  occorrenzeAlfabetica(p, &lista);
  for (Nodo *curr = lista; curr != NULL; curr = curr->next)
  {
    printf("Ch: %c, N: %d\t", curr->ch, curr->n);
  }
  printf("\n");
}
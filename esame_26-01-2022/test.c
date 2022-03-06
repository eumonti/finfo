#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int info;
  struct _node *prox;
} Nodo;

typedef Nodo *Lista;

void printList(Nodo *list)
{
  Nodo *curr;
  for (curr = list; curr != NULL; curr = curr->prox)
  {
    printf("%c ", curr->info);
  }
  printf("\n");
}

Lista LeggiInversi()
{
  Nodo *new;
  Nodo *list;
  Nodo *curr;
  int n;

  scanf(" %d", &n);

  if (n == -1)
    return NULL;

  new = malloc(sizeof(Nodo));
  new->info = n;
  new->prox = NULL;

  list = getData();
  if (list == NULL)
    return new;
  curr = list;
  while (curr->prox != NULL)
    curr = curr->prox;
  curr->prox = new;
  return list;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int info;
  struct _node *prox;
  struct _node *prec;
} Node;

typedef Node *Lista;

void InserisciInOrdine(Lista *pList, int num)
{
  Node *curr;
  Node *newNode;

  newNode = malloc(sizeof(Node));
  newNode->info = num;
  newNode->prox = NULL;
  newNode->prec = NULL;

  if (pList == NULL)
    return newNode;

  if (num < (*pList)->info)
  {
    // Inserimento in testa
    newNode->prox = (*pList);
    (*pList)->prec = newNode;
    *pList = newNode;
  }

  curr = *pList;
  while (num < curr->prox->info)
  {
    newNode = malloc(sizeof(Node));

    newNode->info = num;
    newNode->prec = curr;
    newNode->prox = curr->prox;

    curr->prox->prec = newNode;
    curr->prox = newNode;

    curr = curr->prox;
  }
}

int main()
{
}
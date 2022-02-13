#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  float info;
  struct _node *prox;
} ElemLista;

typedef ElemLista *Lista;

void Fondi(Lista L1, Lista L2, Lista *pL)
{
  ElemLista *nuovo;
  if (L1 == NULL && L2 == NULL)
  {
    *pL = NULL;
    return;
  }
  nuovo = malloc(sizeof(ElemLista));
  *pL = nuovo;
  if (L2 == NULL || (L1 != NULL && L1->info < L2->info))
  {
    nuovo->info = L1->info;
    Fondi(L1->prox, L2, &(*pL)->prox);
    return;
  }
  if (L1 == NULL || (L2 != NULL && L2->info < L1->info))
  {
    nuovo->info = L2->info;
    Fondi(L1, L2->prox, &(*pL)->prox);
    return;
  }
}

int main()
{
  Lista L1 = malloc(sizeof(ElemLista));
  L1->info = 2.0;
  L1->prox = malloc(sizeof(ElemLista));
  L1->prox->info = 4.3;
  L1->prox->prox = malloc(sizeof(ElemLista));
  L1->prox->prox->info = 5.0;
  L1->prox->prox->prox = malloc(sizeof(ElemLista));
  L1->prox->prox->prox->info = 7.5;
  L1->prox->prox->prox->prox = malloc(sizeof(ElemLista));
  L1->prox->prox->prox->prox->info = 10.0;
  L1->prox->prox->prox->prox->prox = NULL;

  Lista L2 = malloc(sizeof(ElemLista));
  L2->info = 1.0;
  L2->prox = malloc(sizeof(ElemLista));
  L2->prox->info = 3.14;
  L2->prox->prox = malloc(sizeof(ElemLista));
  L2->prox->prox->info = 11.1;
  L2->prox->prox->prox = NULL;

  Lista L;
  Fondi(L1, L2, &L);
  Lista curr;
  for (curr = L; curr != NULL; curr = curr->prox)
  {
    printf("%.2f ", curr->info);
  }
  printf("\n");
}
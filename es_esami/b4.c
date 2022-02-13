#include <stdlib.h>
#include <stdio.h>

typedef struct nodo
{
  int tempo;
  int *posizione;
  struct nodo *prox;
} Spostamento;

typedef Spostamento *Traiettoria;

int Distacco2(Traiettoria L1, Traiettoria L2)
{
  if (L1 == NULL && L2 == NULL)
    return -1;

  if (L1->posizione != L2->posizione)
    return (L1->tempo > L2->tempo) ? L1->tempo : L2->tempo;

  if (L2->prox == NULL ||
      (L1->prox != NULL && L1->prox->tempo < L2->prox->tempo))
    return Distacco2(L1->prox, L2);

  return Distacco2(L1, L2->prox);
}

int Distacco(Traiettoria L1, Traiettoria L2)
{
  if (L1 == NULL && L2 == NULL)
    return -1; /* distacco non avviene */
  if (L1 == NULL)
    return L2->tempo;
  if (L2 == NULL)
    return L1->tempo;
  if (L1->tempo < L2->tempo)
    return L1->tempo;
  if (L2->tempo < L1->tempo)
    return L2->tempo;
  if (L1->posizione != L2->posizione)
    return L1->tempo;
  return Distacco(L1->prox, L2->prox);
}

int main()
{
  int arr[] = {1, 1, 1, 1, 1};
  Traiettoria L1 = malloc(sizeof(Spostamento));
  L1->tempo = 3;
  L1->posizione = &arr[0];

  L1->prox = malloc(sizeof(Spostamento));
  L1->prox->tempo = 4;
  L1->prox->posizione = &arr[1];

  L1->prox->prox = malloc(sizeof(Spostamento));
  L1->prox->prox->tempo = 20;
  L1->prox->prox->posizione = &arr[6];

  L1->prox->prox->prox = NULL;

  Traiettoria L2 = malloc(sizeof(Spostamento));
  L2->tempo = 2;
  L2->posizione = &arr[1];

  L2->prox = malloc(sizeof(Spostamento));
  L2->prox->tempo = 4;
  L2->prox->posizione = &arr[1];

  L2->prox->prox = malloc(sizeof(Spostamento));
  L2->prox->prox->tempo = 10;
  L2->prox->prox->posizione = &arr[1];

  L2->prox->prox->prox = malloc(sizeof(Spostamento));
  L2->prox->prox->prox->tempo = 13;
  L2->prox->prox->prox->posizione = &arr[2];

  L2->prox->prox->prox->prox = NULL;

  printf("%d\n", Distacco2(L1, L2));
}
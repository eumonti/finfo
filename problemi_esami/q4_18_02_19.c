#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo
{
  float info;
  struct _nodo *prox;
} Nodo;

typedef Nodo *Lista;

float mediaSenzaRip(Lista L)
{
  Nodo *curs1, *curs2;
  float media;
  float n;

  media = 0;
  n = 0;
  for (curs1 = L; curs1 != NULL; curs1 = curs1->prox)
  {
    curs2 = L;
    while (curs2 != curs1 && curs1->info != curs2->info) // Verifico se l'ho già visto
      curs2 = curs2->prox;
    if (curs2 == curs1) // Non l'ho già visto
    {
      n++;
      media += curs1->info;
    }
    // Altrimenti non lo considerare
    // Salta al prossimo
  }
  media /= n;
  return media;
}

int main()
{
  Lista L = malloc(sizeof(Nodo));
  L->info = 8;
  L->prox = malloc(sizeof(Nodo));
  L->prox->info = 3;
  L->prox->prox = malloc(sizeof(Nodo));
  L->prox->prox->info = 4;
  L->prox->prox->prox = malloc(sizeof(Nodo));
  L->prox->prox->prox->info = 3;
  L->prox->prox->prox->prox = malloc(sizeof(Nodo));
  L->prox->prox->prox->prox->info = 7;
  L->prox->prox->prox->prox->prox = NULL;
  float res = mediaSenzaRip(L);
  printf("%.2f\n", res);
}
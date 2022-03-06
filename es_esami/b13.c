#include <stdlib.h>
#include <stdio.h>

typedef struct nodo
{
  float info;
  struct nodo *prox;
} Nodo;

typedef Nodo *Lista;

float Mediano(Lista L)
{
  Nodo *fast;
  Nodo *slow;
  float sumSlow, sumFast;
  int moveSlow;

  if (L == NULL)
    return 0;

  sumSlow = 0;
  sumFast = 0;
  fast = L;
  slow = L;
  moveSlow = 0;
  while (fast->prox != NULL)
  {
    if (moveSlow)
    {
      sumSlow -= slow->info;
      slow = slow->prox;
    }
    moveSlow = !moveSlow;
    sumFast += fast->info;
    fast = fast->prox;
  }
  sumFast += fast->info;
  sumSlow -= slow->info;

  printf("Somma moduli differenze: ");
  if (moveSlow) // Numero di nodi pari
  {
    printf("%.2f", sumFast + 2 * sumSlow);
    return (slow->info + slow->prox->info) / 2;
  }

  printf("%.2f", (sumFast + 2 * sumSlow) + slow->info);
  return slow->info;
}

Nodo *CentroLista(Lista Lis)
{
  Nodo *curr;
  Nodo *centro;
  double med, inc, diff;
  int dispari = 1;
  if (Lis == NULL)
    return NULL;
  curr = Lis;
  centro = curr;
  med = centro->info;
  diff = 0.0;
  curr = curr->prox;
  while (curr != NULL)
  {
    dispari = 1 - dispari;
    if (dispari == 1)
    {
      inc = centro->prox->info - med;
      med = centro->prox->info;
      diff = diff + curr->info - med;
      centro = centro->prox;
    }
    else
    {
      inc = (centro->prox->info - med) / 2.0;
      med = med + inc;
      diff = diff + inc + curr->info - med;
    }
    curr = curr->prox;
  }
  printf("\n somma delle differenze dal mediano %f, %f", med,
         diff);
  return centro;
}

int main()
{
  int arr[] = {1, 3, 9};
  int len = sizeof(arr) / sizeof(arr[0]);
  Nodo **pCurr;
  Lista L;

  pCurr = &L;
  for (int i = 0; i < len; i++)
  {
    *pCurr = malloc(sizeof(Nodo));
    (*pCurr)->info = arr[i];
    pCurr = &(*pCurr)->prox;
  }
  *pCurr = NULL;
  printf("\n%f\n", Mediano(L));
}
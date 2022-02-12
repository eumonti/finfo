// Un polinomio è rappresentato da una lista dinamica. Ciascun elemento della lista è relativo a
// uno dei termini del polinomio, e contiene un grado intero positivo e il coefficiente float del termine di quel
// grado. I nodi sono ordinati per grado decrescente. Sono presenti solo i nodi relativi a termini con
// coefficiente non nullo (diverso da 0.0); per ogni grado è presente un solo nodo. Scrivere un
// sottoprogramma che riceve in ingresso due polinomi e restituisce un terzo polinomio che rappresenta il
// prodotto tra i due. ***

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int grado;
  float coeff;
  struct nodo *prox;
} Nodo;

typedef Nodo *Polinomio;

// Nodi ordinati per grado decrescente

/*
3->1->NULL
4->3->2->1->NULL
*/

Polinomio Prodotto(Polinomio P1, Polinomio P2)
{
  Polinomio res;
  Nodo *curr1, *curr2;
  Nodo **pCurrRes;
  Nodo *tmp;

  res = NULL;
  for (curr1 = P1; curr1 != NULL; curr1 = curr1->prox)
  {
    for (curr2 = P2; curr2 != NULL; curr2 = curr2->prox)
    {
      pCurrRes = &res;
      while (*pCurrRes != NULL && (*pCurrRes)->grado > curr1->grado + curr2->grado) // Cerco termini con stesso grado
        pCurrRes = &(*pCurrRes)->prox;

      if (*pCurrRes != NULL && (*pCurrRes)->grado == (curr1->grado + curr2->grado)) // Se ho trovato termine con stesso grado
      {
        (*pCurrRes)->coeff += curr1->coeff * curr2->coeff;
      }
      else // Se non l'ho trovato
      {
        if (*pCurrRes != NULL)
          tmp = *pCurrRes;
        else // Inserimento in coda
          tmp = NULL;
        *pCurrRes = malloc(sizeof(Nodo));
        (*pCurrRes)->grado = curr1->grado + curr2->grado;
        (*pCurrRes)->coeff = curr1->coeff * curr2->coeff;
        (*pCurrRes)->prox = tmp;
      }
    }
  }

  return res;
}

Polinomio CostruisciPolinomio(float *arr)
{
  Polinomio res;
  Nodo **pCurr;
  pCurr = &res;
  for (int i = 5; i >= 0; i--)
  {
    if (arr[5 - i] != 0)
    {
      *pCurr = malloc(sizeof(Nodo));
      (*pCurr)->grado = i;
      (*pCurr)->coeff = arr[5 - i];
      pCurr = &(*pCurr)->prox;
    }
  }
  *pCurr = NULL;
  return res;
}

void StampaPolinomio(Polinomio P)
{
  if (P == NULL)
    return;
  printf("%.2fx^(%d)+", P->coeff, P->grado);
  StampaPolinomio(P->prox);
}

int main()
{
  Polinomio P1, P2;
  float arr1[] = {6, 0, 7, 2, 0, 0};
  float arr2[] = {0, 0, 19, 8, 0, 3};
  P1 = CostruisciPolinomio(arr1);
  P2 = CostruisciPolinomio(arr2);
  StampaPolinomio(P1);
  printf("\n");
  StampaPolinomio(P2);
  printf("\n");
  Polinomio res = Prodotto(P1, P2);
  printf("DBG:%d\n", res->grado);
  StampaPolinomio(res);
  printf("\n");
}
/*
Quesito 2. 25/6/21 (punti 11).
Una lista dinamica bidirezionale di interi è costituita da nodi.
Ogni nodo contiene - oltre al campo info di tipo int - anche due campi di tipo puntatore:
un campo prox che punta al successivo nodo e un campo prec che punta al nodo precedente.
Così come il puntatore prox dell'ultimo nodo vale NULL, anche il puntatore prec del primo nodo vale NULL.
La testa della lista consiste -come per le classiche liste monodirezionali- nel puntatore al primo
nodo della lista stessa. Si definiscano il tipo di dato Elem del nodo di una lista bidirezionale e
il tipo di dato Lista della (testa) della lista bidirezionale.
Scrivere una procedura ricorsiva void InserisciInOrdine che, ricevendo in ingresso
(i) una lista dinamica bidirezionale ordinata per valori crescenti del campo info e
(ii) un nuovo valore intero da inserire,
modifica la lista inserendovi il nuovo elemento in posizione tale da mantenere l’ordinamento.
 */
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
  Node *new;

  if (*pList == NULL)
  {
    new = malloc(sizeof(Node));
    new->info = num;
    new->prox = NULL;
    new->prec = NULL;
    (*pList) = new;
    return;
  }

  if ((*pList)->info > num)
  {
    new = malloc(sizeof(Node));
    new->info = num;
    new->prox = *pList;
    new->prec = (*pList)->prec;

    if ((*pList)->prec == NULL)
    {
      (*pList)->prec = new;
      *pList = new;
      return;
    }
    (*pList)->prec = new;
    *pList = new;

    return;
  }

  if ((*pList)->prox == NULL)
  {
    new = malloc(sizeof(Node));
    new->info = num;
    (*pList)->prox = new;
    new->prec = *pList;
    new->prox = NULL;
    return;
  }
  InserisciInOrdine(&(*pList)->prox, num);
}

void StampaLista(Lista L)
{
  Node *curr;
  printf("\nprec\tcurr\tprox\n");
  for (curr = L; curr != NULL; curr = curr->prox)
  {
    curr->prec != NULL ? printf("%d\t", curr->prec->info) : printf("NULL\t");
    printf("%d\t", curr->info);
    curr->prox != NULL ? printf("%d\n", curr->prox->info) : printf("NULL\t");
  }
  printf("\n");
}

int main()
{
  int i;
  Lista l;
  Node **pCurr, *prec;
  int arr[] = {1, 2, 4, 5, 7, 19, 29};
  int len = sizeof(arr) / sizeof(arr[0]);

  prec = NULL;
  pCurr = &l;
  for (i = 0; i < len; i++)
  {
    *pCurr = malloc(sizeof(Node));
    (*pCurr)->info = arr[i];
    (*pCurr)->prec = prec;
    prec = *pCurr;
    pCurr = &(*pCurr)->prox;
  }
  *pCurr = NULL;

  StampaLista(l);
  InserisciInOrdine(&l, 12);
  StampaLista(l);
}
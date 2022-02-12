// Esercizio A6 a. Un oggetto, caratterizzato da un’altezza e un peso (entrambi float), è rappresentato tramite
// un nodo in una lista dinamica. Ogni nodo dispone di due puntatori; il primo punta all’elemento
// immediatamente successivo secondo un ordinamento (crescente) in peso, il secondo punta all’elemento
// immediatamente successivo secondo un ordinamento (crescente) in altezza. Scrivere un sottoprogramma
// che -ricevendo in ingresso una lista, un valore di peso e un valore di altezza- inserisce nella lista un nuovo
// elemento caratterizzato dai valori di peso e altezza ricevuti in ingresso.

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  float weight;
  float height;
  struct _node *nextByWeight;
  struct _node *nextByHeight;
} Node;

typedef struct _list
{
  Node *weightHead;
  Node *heightHead;
} List;

Node *newNode(int weigth, int height);                   // Crea nuovo nodo con puntatori next a NULL
void printList(List l, int mode);                        // mode=1 stampa by weigth, 0 by height
List makeSampleList();                                   // Crea una lista di prova
void inserisci(List *pList, float weight, float height); // Inserisce nella lista un nuovo elemento caratterizzato dai valori di peso e altezza ricevuti in ingresso
void cancella(List *pList, float height);                // Cancella elemento con altezza height

int main()
{
  List l = makeSampleList();
  printList(l, 1);

  inserisci(&l, 100, 72);
  cancella(&l, 7);
  printList(l, 1);
}

void inserisci(List *pList, float weight, float height)
{
  Node **pCurr; // Inizialmente è pList, poi punta al campo next del nodo. In questo modo non c'è bisogno di tenere il riferimento all'elemento precedente.
  Node *new;

  // Make new node
  new = newNode(weight, height); // Ha già i next a NULL

  // Heigth pointers
  pCurr = &(pList->heightHead);
  while (*pCurr != NULL && (*pCurr)->height < height)
    pCurr = &(*pCurr)->nextByHeight;

  new->nextByHeight = (*pCurr);
  *pCurr = new;

  // Weight pointers
  pCurr = &(pList->weightHead);
  while (*pCurr != NULL && (*pCurr)->weight < weight)
    pCurr = &(*pCurr)->nextByWeight;

  new->nextByWeight = (*pCurr);
  *pCurr = new;
}

void cancella(List *pList, float height) // Cancella elemento con altezza height
{
  Node **pCurr;
  Node *tmp;

  pCurr = &((*pList).heightHead);
  while (*pCurr != NULL && (*pCurr)->height != height)
    pCurr = &(*pCurr)->nextByHeight;

  if (*pCurr == NULL)
  {
    printf("Elemento non trovato, lista rimasta invariata.\n");
    return;
  }
  *pCurr = (*pCurr)->nextByHeight;

  pCurr = &(pList->weightHead);
  while (*pCurr != NULL && (*pCurr)->height != height)
    pCurr = &(*pCurr)->nextByWeight;

  tmp = *pCurr;
  *pCurr = (*pCurr)->nextByWeight;

  free(tmp);
}

List makeSampleList()
{
  List l;
  Node *wList, *wCurr;
  Node *hList, *hCurr;

  wList = newNode(1, 3);
  hList = newNode(10, 1);

  l.heightHead = hList;
  l.weightHead = wList;

  wCurr = newNode(3, 7);
  hCurr = newNode(8, 2);

  wList->nextByWeight = wCurr;
  wCurr->nextByWeight = hCurr;
  hCurr->nextByWeight = hList;

  hList->nextByHeight = hCurr;
  hCurr->nextByHeight = wList;
  wList->nextByHeight = wCurr;
  return l;
}

void printList(List l, int mode) // mode=1 prints by weigth, 0 by height
{
  Node *curr;
  if(l.weightHead == NULL)
  {
    printf("Lista vuota.\n");
    return;
  }
  switch (mode)
  {
  case 1:
    for (curr = l.weightHead; curr != NULL; curr = curr->nextByWeight)
    {
      printf("|W: %.2f|H: %.2f|\t", curr->weight, curr->height);
    }
    printf("\n");
    break;
  case 0:
    for (curr = l.heightHead; curr != NULL; curr = curr->nextByHeight)
    {
      printf("|W: %.2f|H: %.2f|\t", curr->weight, curr->height);
    }
    printf("\n");
    break;
  default:
    printf("Invalid mode specified.\n");
    break;
  }
}

Node *newNode(int weigth, int height)
{
  Node *new;
  new = malloc(sizeof(Node));
  new->weight = weigth;
  new->height = height;
  new->nextByWeight = NULL;
  new->nextByHeight = NULL;
  return new;
}
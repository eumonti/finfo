/*
  Data una lista dinamica di interi, si vuole ordinare solamente i suoi valori pari, lasciando i valori dispari
  inalterati. Ad esempio
  la lista 19->10->8->13->4->9->2->5
  diviene 19->2->4->13->8->9->10->5 .
  Si scriva una procedura ricorsiva void che, ricevendo in ingresso una lista dinamica di interi, la modifica
  ordinando solo i suoi valori pari lasciando inalterati i valori dispari.
  NOTA: si consiglia di ispirarsi liberamente all’algoritmo di Bubblesort, il quale durante la prima passata
  porta l’elemento di valore minimo in testa alla lista, durante la seconda esegue la stessa operazione sulla
  sottolista che inizia con il secondo elemento e così via..
*/
#include <stdlib.h>
#include "../liste_dinamiche/lib/linkedlist_int.h"

void ordinaPari(Node *list)
{
  Node *cursA, *cursB;
  Node *lowestNumNode;
  int tmp;
  for (cursA = list; cursA != NULL; cursA = cursA->next)
  {
    if (cursA->data % 2 == 0)
    {
      lowestNumNode = cursA;
      // Find lowest num among remaining elements
      for (cursB = cursA->next; cursB != NULL; cursB = cursB->next)
      {
        if (cursB->data % 2 == 0 && cursB->data < lowestNumNode->data)
        {
          lowestNumNode = cursB;
        }
      }
      // Swap current num and lowestNum
      tmp = cursA->data;
      cursA->data = lowestNumNode->data;
      lowestNumNode->data = tmp;
    }
  }
}

// 19->10->8->1
// 19->8->10->1

void ordinaPari2(Node **pList)
{
  Node **pCursA;
  Node *cursB;
  Node *lowest;
  Node *prevLowest; // Node before lowest guy
  Node *lowestNext;
  int swap;
  prevLowest = NULL;
  lowest = NULL;
  for (pCursA = pList; *pCursA != NULL; pCursA = &(*pCursA)->next)
  {
    // Find lowest value in list and swap it with cursA
    if ((*pCursA)->data % 2 == 0)
    {
      lowest = *pCursA;
      cursB = (*pCursA)->next;
      swap = 0;
      while (cursB->next != NULL)
      {
        if (cursB->next->data % 2 == 0 && cursB->next->data < lowest->data)
        {
          prevLowest = cursB;
          lowest = cursB->next;
          swap = 1;
        }
        cursB = cursB->next;
      }
      // Swap stuff
      // tmp = lowest->data;
      // lowest->data = (*pCursA)->data;
      // (*pCursA)->data = tmp;
      lowestNext = lowest->next;
      if (swap)
      {
        lowest->next = (*pCursA)->next;
        (*pCursA)->next = lowestNext;
        if (prevLowest != NULL)
          prevLowest->next = *pCursA;
        *pCursA = lowest;
      }
    }
  }
}

void ordinaPariRic(Node **pList)
{
  Node **pCurr, **pLowest;
  Node *tmp;
  int lowestNum;

  if (*pList == NULL || (*pList)->next == NULL)
    return;

  if ((*pList)->data % 2 != 0) // Se non è pari
  {
    ordinaPariRic(&(*pList)->next);
    return;
  }
  // Se è pari cerco il prossimo nodo pari più piccolo e li scambio
  pLowest = NULL;
  pCurr = &(*pList)->next;
  lowestNum = (*pCurr)->data;
  while (*pCurr != NULL)
  {
    if ((*pCurr)->data % 2 == 0 && (*pCurr)->data < lowestNum)
    {
      lowestNum = (*pCurr)->data;
      pLowest = pCurr;
    }
    pCurr = &(*pCurr)->next;
  }

  if (pLowest == NULL) // Non ho trovato un nodo più piccolo
  {
    ordinaPariRic(&(*pList)->next);
    return;
  }
  tmp = (*pList)->next;
  (*pList)->next = (*pLowest)->next;
  (*pLowest)->next = tmp;
  tmp = *pList;
  *pList = *pLowest;
  *pLowest = tmp;
  ordinaPariRic(&(*pList)->next);
}

void *ordinaPariRic2(Node **pList)
{
  Node **pCurr, **pLowest;
  Node *tmp;
  int lowestNum;

  if (*pList == NULL || (*pList)->next == NULL)
    return;

  if ((*pList)->data % 2 != 0) // Se è pari
  {
    pLowest = NULL;
    pCurr = &(*pList)->next;
    lowestNum = (*pCurr)->data;
    while (*pCurr != NULL)
    {
      if ((*pCurr)->data % 2 == 0 && (*pCurr)->data < lowestNum)
      {
        lowestNum = (*pCurr)->data;
        pLowest = pCurr;
      }
      pCurr = &(*pCurr)->next;
    }

    if (pLowest == NULL) // Non ho trovato un nodo più piccolo
    {
      ordinaPariRic(&(*pList)->next);
      return;
    }
    tmp = (*pList)->next;
    (*pList)->next = (*pLowest)->next;
    (*pLowest)->next = tmp;
    tmp = *pList;
    *pList = *pLowest;
    *pLowest = tmp;
  }
  ordinaPariRic(&(*pList)->next);
}

/* void ordinaPari2(Node **pList)
{
  Node **pCurr1;
  Node **pCurr2;
  Node *tmp;
  Node **pLowest;
  pCurr1 = pList;
  while (*pCurr1 != NULL)
  {
    pLowest = pCurr1;
    if ((*pCurr1)->data % 2 == 0)
    {
      pCurr2 = &(*pCurr1)->next;
      while (*pCurr2 != NULL)
      {
        if ((*pCurr2)->data % 2 == 0 && (*pCurr2)->data < (*pLowest)->data)
        {
          pLowest = pCurr2;
        }
        pCurr2 = &(*pCurr2)->next;
      }
      // Swap pLowest with pCurr1
      // tmp = (*pCurr1)->next;
      // (*pCurr1)->next = (*pLowest)->next;
      (*pCurr1)->next =
          (*pLowest)->next = (*pCurr1);
      tmp = *pCurr1;
      *pCurr1 = *pLowest;
      *pLowest = tmp;
    }
    pCurr1 = &(*pCurr1)->next;
  }
}
*/

int main()
{
  Node *list = getSequence("files/sequence.txt");
  printList(list);
  ordinaPariRic2(&list);
  printList(list);
}
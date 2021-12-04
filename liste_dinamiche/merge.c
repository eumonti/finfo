/*
Sono date due liste dinamiche di numeri reali, ciascuna ordinata in ordine
crescente. Si suppone che uno stesso numero reale non compaia mai due volte
nelle due liste. Scrivere una funzione RICORSIVA Merge che, ricevendo in
ingresso le due liste ordinate di numeri reali, restituisca una nuova lista
dinamica che contiene in ordine crescente tutti i numeri reali compresi nelle
due liste. 

Ad esempio:  applicando Merge a 
  (-2.3 -> 0.8 -> 2.7 -> 4.1)  e  ( -4.0 -> 1.2 -> 2.3 -> 4.8) 
si ottiene la lista
  (-4.0 -> -2.3 -> 0.8 -> 1.2 -> 2.3 -> 2.7 -> 4.1 -> 4.8)
*/
#include <stdio.h>
#include <stdlib.h>
#include "lib/linkedlist.h"

Node *merge(Node *pHead1, Node *pHead2)
{
  Node *pNewNode;

  // If they are both null, last element is NULL
  if (pHead1 == NULL && pHead2 == NULL)
  {
    return NULL;
  }
  pNewNode = malloc(sizeof(Node));

  // If only pHead1 is null, add data from list2
  if (pHead1 == NULL || (pHead2 != NULL && pHead2->data < pHead1->data)) // Add lower element
  {
    pNewNode->data = pHead2->data;
    pNewNode->next = merge(pHead1, pHead2->next);
  }
  else // Lower element is in pHead1
  {
    pNewNode->data = pHead1->data;
    pNewNode->next = merge(pHead1->next, pHead2);
  }
  return pNewNode;
}

int main()
{
  Node *list1 = getSequence("sequence1.txt");
  Node *list2 = getSequence("sequence2.txt");
  printList(list1);
  printList(list2);
  Node *result = merge(list1, list2);
  printList(result);
}
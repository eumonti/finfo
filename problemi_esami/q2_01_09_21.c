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

void ordinaPari2(Node **pList)
{
  Node *cursA, *cursB, *tmpA;
  Node *prevLowestNumNode;
  cursA = *pList;
  while (cursA->next != NULL)
  {
    tmpA = cursA;
    prevLowestNumNode = cursA->next;
    for (cursB = cursA; cursB->next != NULL; cursB = cursB->next)
    {
      if (prevLowestNumNode->next->data > cursB->next->data)
      {
        prevLowestNumNode = cursB;
      }
      // Swap
      prevLowestNumNode->next->next = cursA->next->next;
      cursA->next = prevLowestNumNode->next;

      cursA = tmpA->next;
    }
  }
}

int main()
{
  Node *list = getSequence("files/sequence.txt");
  ordinaPari2(&list);
  printList(list);
}
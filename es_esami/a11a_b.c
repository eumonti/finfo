#include <stdlib.h>
#include "../liste_dinamiche/lib/linkedlist_int.h"

typedef Node *Binario;

/* Procedura ricorsiva */

void RLC_void(Binario num, Node **pList, int currDigit)
{
  if (num == NULL)
    return;

  if (*pList == NULL)
  {
    *pList = malloc(sizeof(Node));
    (*pList)->data = 0;
    (*pList)->next = NULL;
  }

  if (num->data == currDigit)
  {
    (*pList)->data++;
    RLC_void(num->next, pList, currDigit);
  }
  else
  {
    RLC_void(num, &(*pList)->next, !currDigit);
  }
}

/* Funzione ricorsiva */
Node *RLC(Binario num, Node *currNode, int currDigit)
{
  if (num == NULL)
    return currNode;

  if (currNode == NULL)
  {
    currNode = malloc(sizeof(Node));
    currNode->next = NULL;
    currNode->data = 0;
  }

  if (num->data == currDigit)
  {
    currNode->data++;
    currNode = RLC(num->next, currNode, currDigit);
  }
  else
    currNode->next = RLC(num, NULL, !currDigit);

  return currNode;
}

void RLCproc(Node **pL, int cifra_corr, Binario bin) // Caglioti ricorsiva
{
  if (bin == NULL)
    return;
  if (*pL == NULL)
  {
    *pL = malloc(sizeof(Node));
    (*pL)->data = 0;
    (*pL)->next = NULL;
    cifra_corr = 1;
  }
  if (bin->data == cifra_corr)
  {
    (*pL)->data++;
    RLCproc(pL, cifra_corr, bin->next);
  }
  else
  {
    (*pL)->next = malloc(sizeof(Node));
    ((*pL)->next)->data = 1;
    ((*pL)->next)->next = NULL;
    RLCproc(&((*pL)->next), bin->data, bin->next);
  }
}

int main()
{
  Node *codifica = NULL;
  Binario num = getSequence("sequence.txt");
  // codifica = RLC(num, codifica, 0);
  // RLC_void(num, &codifica, 0);
  RLCproc(&codifica, 1, num);
  printList(codifica);
}
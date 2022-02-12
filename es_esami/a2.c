// Esercizio A2. Una matrice di interi si può rappresentare mediante una lista dinamica bidimensionale, in cui
// ciascun nodo –oltre al campo numerico- ha due puntatori: uno al prossimo nodo lungo la stessa riga (tale
// puntatore vale NULL per ciascun nodo corrispondente a un elemento alla fine di una riga), e uno al
// prossimo nodo lungo la colonna (tale puntatore vale NULL per ciascun nodo corrispondente alla fine di una
// colonna). La testa della lista è il puntatore al nodo che contiene l’elemento [0][0] della matrice. Si scriva un
// sottoprogramma che riceve in ingresso una matrice di dimensioni definite tramite direttive #define, e
// restituisce la lista dinamica che la rappresenta nel modo sopra descritto. ***
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 3

typedef struct _node
{
  int data;
  struct _node *nextRow; // Puntatore al nodo successivo nella stessa riga
  struct _node *nextCol;
} Node;

typedef Node *List;

List make2dList(int matrix[ROWS][COLS])
{
  int i, j;
  List list;
  Node **pRowHead, **pCurr, *prevRowNode;
  prevRowNode = NULL;
  pRowHead = &list;
  for (i = 0; i < ROWS; i++)
  {
    pCurr = pRowHead;
    for (j = 0; j < COLS; j++)
    {
      *pCurr = malloc(sizeof(Node));
      (*pCurr)->data = matrix[i][j];
      if (prevRowNode != NULL)
      {
        prevRowNode->nextCol = *pCurr;
        prevRowNode = prevRowNode->nextRow;
      }

      pCurr = &(*pCurr)->nextRow;
    }
    *pCurr = NULL;
    prevRowNode = *pRowHead;
    pRowHead = &(*pRowHead)->nextCol;
  }
  return list;
}

void printList(List l)
{
  Node *curr;
  if (l == NULL)
  {
    printf("List is null\n");
    return;
  }
  for (curr = l; curr != NULL; curr = curr->nextCol)
  {
    printf("%d ", curr->data);
  }
  printf("\n");
}

int main()
{
  int mat[ROWS][COLS] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9},
                         {10, 11, 12}};
  List l = make2dList(mat);
  printList(l);
}
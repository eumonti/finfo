/*
  Una lista dinamica contiene elementi con valori interi -tutti distinti- disposti in ordine crescente.
  Si considerino le differenze (positive) tra ogni elemento e ciascuno degli elementi che lo precedono: si scriva
  una funzione che -ricevendo in ingresso una lista dinamica di interi ordinata- restituisce al chiamante la
  differenza che è presente il maggior numero di volte. In caso di più differenze a pari merito la funzione ne
  può restituire una qualunque, ad esempio quella più comoda da ottenere.
  Si definiscano anche i tipi delle eventuali strutture di dati intermedie utilizzate.
  Ad esempio nella lista L->(1)->(6)->(7)->(12)->(13)->(14)->(18)->(20)->(22)->(25)-| la differenza pari 6 è
  quella che si presenta il maggior numero di volte (cinque): tra 7 e 1, tra 12 e 6, tra 13 e 7, tra 18 e 12 e tra
  20 e 14.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

/*

OUTPUT: 6 (5 volte)
L->(1)->(6)->(7)->(12)->(13)->(14)->(18)->(20)->(22)->(25)->NULL
       5   1     5     1     1     4     2     2    3

*/

/*
for i 0 to n
  for j : i+1 to n
    diff = arr[j] - arr[i];


// Numero di differenze:
// 1 2 3 4
/*
  1->2
  1->3
  1->4
  2->3
  2->4
  3->4

  allocate array of size (n - 1)(n)/2
*/

// ingresso: list (ordinata)
// uscita: differenza presente più volte

void printArr(int *arr, int len)
{
  int i;
  for (i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

typedef Node *List;

int fun(List list)
{
  List diffList;
  Node **pCurrNode;
  Node *cursA, *cursB;
  int currCount;
  int maxCount = -1;
  int result;

  diffList = NULL;
  pCurrNode = &diffList;
  for (cursA = list; cursA != NULL; cursA = cursA->next)
  {
    for (cursB = cursA->next; cursB != NULL; cursB = cursB->next)
    {
      // Aggiungi la differenza a diffList
      *pCurrNode = malloc(sizeof(Node));
      (*pCurrNode)->data = cursB->data - cursA->data;
      pCurrNode = &((*pCurrNode)->next);
    }
  }
  *pCurrNode = NULL;

  // Cerca l'elemento più basso in diffList
  currCount = 0;
  maxCount = -1;
  result;
  for (cursA = diffList; cursA != NULL; cursA = cursA->next)
  {
    for (cursB = cursA->next; cursB != NULL; cursB = cursB->next)
    {
      if (cursA->data == cursB->data)
        currCount++;
    }
    if (currCount > maxCount)
    {
      maxCount = currCount;
      result = cursA->data;
    }
    currCount = 0;
  }
  return result;
}

Node *arrToLinkedList(int *arr, int len)
{
  int i;
  Node *pHead;
  Node **ppCurr;
  ppCurr = &pHead;
  for (i = 0; i < len; i++)
  {
    *ppCurr = malloc(sizeof(int));
    (*ppCurr)->data = arr[i];
    ppCurr = &((*ppCurr)->next);
  }
  *ppCurr = NULL;
  return pHead;
}

void printLinkedList(Node *list)
{
  Node *curr = list;
  while (curr != NULL)
  {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main()
{
  int arr[] = {1, 6, 7, 12, 13, 14, 18, 20, 22, 25};
  int n = sizeof(arr) / sizeof(arr[0]);
  Node *list = arrToLinkedList(arr, n);
  printLinkedList(list);
  printf("Result is: %d", fun(list));
}
#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 9

typedef struct _node
{
  int *data;
  struct _node *next;
} Node;

void printList(Node *list, int *pFirst)
{
  while (list != NULL)
  {
    printf("%ld ", list->data - pFirst + 1);
    list = list->next;
  }
  printf("\n");
}

// Procedura ricorsiva che costruisce una lista dinamica contentente i puntatori ai massimi locali
void MaxLoc(Node **ppHead, int *arr, int len)
{
  // printf("%d\n", len);
  if (len < 1)
  {
    *ppHead = NULL;
    return;
  }

  if (
      (ARR_LEN - len == 0 && *arr > *(arr + 1)) || // First element, check only second
      (len == 1 && *(arr) > *(arr - 1)) ||         // Last element
      (*arr > *(arr + 1) && *arr > *(arr - 1))     // Generic element in middle
  )
  {
    *ppHead = malloc(sizeof(Node));
    (*ppHead)->next = NULL;
    (*ppHead)->data = arr;
    MaxLoc(&((*ppHead)->next), arr + 1, len - 1);
  }
  else
    MaxLoc(ppHead, arr + 1, len - 1);
}

void MaxLocCaglioti(int S[], int N, Node **pL)
{
  Node *temp;
  if (N == 0)
  {
    *pL = NULL;
    return;
  }
  if (N == 1)
  {
    *pL = malloc(sizeof(Node));
    (*pL)->data = S;
    (*pL)->next = NULL;
    return;
  }
  MaxLocCaglioti(S + 1, N - 1, pL);
  if (*S <= *(S + 1))
    return;
  if ((*pL)->data == S + 1)
    (*pL)->data = S;
  else
  {
    temp = malloc(sizeof(Node));
    temp->data = S;
    temp->next = *pL;
    *pL = temp;
  }
}

int main()
{
  // int arr[ARR_LEN] = {3, 2, 1, 4, 7, 3, 4, 2, 6};
  // int arr[ARR_LEN] = {1};
  int arr[] = {3, 4, 1};
  Node *list;
  MaxLocCaglioti(arr, 3, &list);
  printList(list, arr);
}
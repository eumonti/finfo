#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 1

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
  printf("%d\n", len);
  if (len < 1)
    return;
  if (
      ARR_LEN - len == 0 && *arr > *(arr + 1) || // First element, check only second
      len == 1 && *(arr) > *(arr - 1) ||           // Last element
      *arr > *(arr + 1) && *arr > *(arr - 1)     // Generic element in middle
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

int main()
{
  int arr[ARR_LEN] = {3};
  Node *list = NULL;
  MaxLoc(&list, arr, ARR_LEN);
  printList(list, arr);
}
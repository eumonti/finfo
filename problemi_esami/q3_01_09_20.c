#include <stdio.h>
#include <stdlib.h>

#define DIM 10

typedef struct _node
{
  int *data;
  struct _node *next;
} Node;

// La x del drone è sempre negativa
Node *fun(int arr[DIM], float x, float z)
{
  Node *pList;
  Node **ppCurr = &pList;
  int i;
  int j;
  float tan;
  float maxHeight;
  int valid;
  for (i = DIM - 1; i >= 0; i--)
  {
    valid = 1;
    tan = (arr[i] - z) / (i - x);
    for (j = i - 1; j >= 0 && valid; j--)
    {
      maxHeight = (j - x) * tan + z;
      if (arr[j] >= maxHeight)
      {
        valid = 0;
      }
    }
    if (valid)
    {
      // Add pointer to i-th element to linked list
      *ppCurr = malloc(sizeof(Node));
      (*ppCurr)->data = &(arr[i]);
      ppCurr = &((*ppCurr)->next);
    }
  }
  *ppCurr = NULL;
  return pList;
}

int main()
{
  // Contiene le altezze dei cipressi disposti in ordine
  int trees[DIM] = {2, 1, 2, 1, 3, 7, 5, 6, 8, 9};
  Node *list = fun(trees, -3, 2);
  Node *curr = list;
  while (curr != NULL)
  {
    printf("%d\n", *(curr->data));
    curr = curr->next;
  }
}
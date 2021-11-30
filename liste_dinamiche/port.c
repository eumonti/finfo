#include <stdio.h>
#include <stdlib.h>

// Representation of a node
typedef struct _node
{
  int data;
  struct _node *next;
} Node;

// Function to insert node
void insert(Node **root, int item)
{
  Node *temp = malloc(sizeof(Node));
  Node *ptr;
  temp->data = item;
  temp->next = NULL;

  if (*root == NULL)
    *root = temp;
  else
  {
    ptr = *root;
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = temp;
  }
}

void display(Node *root)
{
  while (root != NULL)
  {
    printf("%d ", root->data);
    root = root->next;
  }
}

Node *arrayToList(int arr[], int n)
{
  Node *root = NULL;
  for (int i = 0; i < n; i++)
    insert(&root, arr[i]);
  return root;
}

// Driver code
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  Node *root = arrayToList(arr, n);
  display(root);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  struct _node *next;
  int data;
} Node;

int main()
{
  Node *head;

  // head = malloc(sizeof(Node));
  // second = malloc(sizeof(Node));
  // third = malloc(sizeof(Node));
  // head->next = second;
  // second->next = third;
  // third->next = NULL;

  // printf("%p %p %p\n", head, second, third);

  // head->data = 1;
  // second->data = 2;
  // third->data = 3;

  Node *curr;
  head = malloc(sizeof(Node));
  curr = head;
  int i;
  for (i = 0; i < 9; i++)
  {
    curr->data = i;
    curr->next = malloc(sizeof(Node));
    curr = curr->next;
  }
  curr->data = 9;
  curr->next = NULL;

  curr = head;
  while (curr != NULL)
  {
    printf("%d\n", curr->data);
    curr = curr->next;
  }
}
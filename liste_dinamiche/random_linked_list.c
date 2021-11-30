#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

void printList(Node *head)
{
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

Node *newNode(int data)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

Node *randomList()
{
  int i;
  Node *head, *currNode, *lastNode;

  for (i = 0; i < 10; i++)
  {
    currNode = newNode(random() % 30);
    if (i == 0)
    {
      head = currNode;
    }
    else
    {
      lastNode->next = currNode;
    }
    lastNode = currNode;
  }
  currNode->next = NULL;
  return head;
}

int main()
{
  Node *list = randomList();
  printList(list);
}
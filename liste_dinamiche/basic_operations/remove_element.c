#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

void printList(Node *list);
Node *getSequence(char *fileName);
void freeList(Node *list);

void removeNode(Node *list, int pos)
{
  pos--;
  int i = 0;
  Node *curr = list;
  Node *tmp;
  while (curr->next != NULL)
  {
    if(i == pos)
    {
      tmp = curr->next;
      free(tmp);
      curr->next = curr->next->next;
    }
    i++;
    curr = curr->next;
  }
  
}

int main()
{
  Node *list = getSequence("../sequence.txt");
  printList(list);
  removeNode(list, 3);
  printList(list);
}

void printList(Node *list)
{
  while (list != NULL)
  {
    printf("%d ", list->data);
    list = list->next;
  }
  printf("\n");
}

Node *newNode(int data)
{
  Node *new = malloc(sizeof(Node));
  if (new != NULL)
  {
    new->next = NULL;
    new->data = data;
  }
  return new;
}

Node *getSequence(char *fileName)
{
  FILE *filePtr;

  Node *head = NULL;
  Node *curr, *last;
  int first = 1;

  if ((filePtr = fopen(fileName, "r")) == NULL)
    return NULL;

  while (!feof(filePtr))
  {
    int data;
    fscanf(filePtr, "%d", &data);
    curr = newNode(data);
    if (first)
    {
      head = curr;
      first = 0;
    }
    else
    {
      last->next = curr;
    }
    last = curr;
  }
  curr->next = NULL;

  fclose(filePtr);
  return head;
}

void freeList(Node *list)
{
  Node *nextNode;
  while (list != NULL)
  {
    nextNode = list->next;
    free(list);
    list = nextNode;
  }
}
// Scambio tra i nodi in posizione pari e i nodi in posizione dispari in una lista dinamica.

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

void scambiaNodi(Node **lista) // Scambia nodi in posizione pari con quelli in posizione dispari
{
  if (*lista == NULL || (*lista)->next == NULL)
    return;
  Node *curr;
  Node *next;
  Node *last;

  next = (*lista)->next;

  curr = next;
  last = *lista;
  *lista = curr;

  while (curr != NULL)
  {
    next = curr->next;
    curr->next = last;

    if (next == NULL)
    {
      last->next = next;
      return;
    }
    if (next->next == NULL)
    {
      last->next = next;
      return;
    }
    else
      last->next = next->next;

    curr = next->next;
    last = next;
  }
}

int main()
{
  Node *lista = getSequence("sequence.txt");
  scambiaNodi(&lista);
  printList(lista);
  freeList(lista);
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


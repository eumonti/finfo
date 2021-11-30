#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

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

  // fseek(filePtr, 0, SEEK_END);
  // int size = ftell(filePtr);

  // if (0 == size)
  // {
  //   return NULL;
  // }

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
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

void printList(Node *list, int len)
{
  while (list != NULL && len-- >= 0)
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

Node *longestIncreasing(Node *head, int *len) // Strictly increasing
{
  Node *currNode = head; // Nodo corrente
  Node *currHead = head; // Testa della sequenza in analisi
  Node *maxHead = NULL;  // Testa della più lunga sequenza crescente
  int currLen = 0;
  int maxLen = 0;

  while (currNode->next != NULL)
  {
    if (currNode->data <= currNode->next->data)
    {
      currLen++;
    }
    else if (currLen > maxLen)
    {
      maxLen = currLen;
      maxHead = currHead;
    }
    else
    {
      currHead = currNode->next;
      currLen = 0;
    }

    currNode = currNode->next;
  }
  printf("Max len: %d\n", maxLen);
  *len = maxLen;
  return maxHead;
}

int main()
{
  Node *sequence = getSequence("sequence.txt");
  int len;
  Node *res = longestIncreasing(sequence, &len);
  printf("Max len: %d\n", len);
  printList(res, len);
  freeList(sequence);
}
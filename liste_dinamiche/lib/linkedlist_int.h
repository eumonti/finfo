#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

void printList(Node *list);
Node *newNode(int data);
Node *getSequence(char *fileName);
void freeList(Node *list);

#endif
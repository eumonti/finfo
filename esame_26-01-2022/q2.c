// Quesito 2: funzione ricorsiva che riceve in ingresso caratteri e li aggiunge in una lista dinamica invertendoli (il primo carattere come ultimo della lista e l'ultimo come primo)
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  char data;
  struct _node *next;
} Node;

void printList(Node *list)
{
  Node *curr;
  for (curr = list; curr != NULL; curr = curr->next)
  {
    printf("%c ", curr->data);
  }
  printf("\n");
}

Node *getData()
{
  char userInput;
  Node *new;
  Node *list;
  Node *curr;

  scanf(" %c", &userInput);

  if (userInput == '1')
    return NULL;

  new = malloc(sizeof(Node));
  new->data = userInput;
  new->next = NULL;

  list = getData();
  if (list == NULL)
    return new;
  curr = list;
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = new;
  return list;
}

Node *getData2(int n)
{
  Node *new;
  char ch;

  if (n == 0)
    return NULL;

  new = malloc(sizeof(Node));
  new->next = getData2(n - 1);

  scanf(" %c", &ch);
  new->data = ch;
  return new;
}

void getData3(Node **pLista)
{
  Node *nuovo;
  char ch;

  scanf(" %c", &ch);
  if (ch == '-')
    return;

  nuovo = malloc(sizeof(Node)); // Inserimento in testa
  nuovo->data = ch;
  nuovo->next = *pLista;
  *pLista = nuovo;
  getData3(pLista);
}

int main()
{
  Node *list = NULL;
  getData3(&list);
  printList(list);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int data;
  struct _node *next;
} TipoElemento;

typedef enum
{
  false,
  true
} boolean;

TipoElemento *RiempiLista(void);
/* crea una lista dinamica contenente interi positivi
o nulli letti da tastiera e restituisce la testa di tale lista.  
L'input da tastiera termina quando l'utente
inserisce un numero negativo */

void StampaLista(TipoElemento *Testa); /* stampa a schermo gli interi contenuti nella
lista avente testa Testa */

boolean ContieneDoppioni(TipoElemento *Testa); /* restituisce true se almeno uno dei
numeri contenuti nella lista avente testa Testa compare due o più volte nella lista;
altrimenti restituisce false */

int main()
{
  TipoElemento *lista = RiempiLista();
  StampaLista(lista);
  ContieneDoppioni(lista) ? printf("Contiene doppioni\n") : printf("Non contiene doppioni\n");
}

TipoElemento *RiempiLista(void)
{
  int data;
  TipoElemento *head, *lastNode, *newNode;
  scanf("%d", &data);
  if (data < 0)
    return NULL;
  head = malloc(sizeof(TipoElemento));
  head->data = data;
  newNode = head;
  lastNode = head;
  scanf("%d", &data);

  while (data >= 0)
  {
    newNode = malloc(sizeof(TipoElemento));
    newNode->data = data;
    lastNode->next = newNode;
    lastNode = newNode;
    scanf("%d", &data);
  }
  newNode->next = NULL;
  return head;
}

void StampaLista(TipoElemento *Testa)
{
  TipoElemento *curr;
  curr = Testa;
  while (curr != NULL)
  {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

boolean ContieneDoppioni(TipoElemento *Testa)
{
  TipoElemento *p1, *p2;
  p1 = Testa;
  p2 = Testa;

  if (Testa == NULL || Testa->next == NULL)
    return false;

  while (p1 != NULL)
  {
    p2 = p1->next;
    while (p2 != NULL)
    {
      if (p1->data == p2->data)
        return true;
      p2 = p2->next;
    }
    p1 = p1->next;
  }
  return false;
}
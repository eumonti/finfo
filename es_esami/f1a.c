/*
ESERCIZIO F1a
Sia detto TipoDato un tipo di dato composto da un intero e un float.
Si consideri un file di testo, Input.txt, composto da linee ciascuna delle quali contiene un numero intero, il
carattere ':', un numero float, e un carattere '\n' conclusivo.
Si scriva un sottoprogramma riceve in ingresso un puntatore a FILE associato al file Input.txt (già aperto dal
programma chiamante) e crea una lista dinamica. Gli elementi della lista dinamica hanno campo dati di tipo
TipoDato, e ciascuno di essi contiene i dati di una delle linee del file. Gli elementi della lista devono avere lo
stesso ordine delle linee del file: alla prima linea corrisponderà pertanto il primo elemento della lista, e così
via. Il sottoprogramma deve restituire la testa L della lista. Ad esempio, se il file contiene
 11:1.1
 22:2.2
 33:3.3
la lista da esso generata sarà
 L -> (11,1.1) -> (22,2.2) -> (33,3.3)
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int n;
  float f;
} TipoDato;

typedef struct nodo
{
  TipoDato dato;
  struct nodo *next;
} Nodo;

typedef Nodo *Lista;

Lista CreaLista(FILE *fp)
{
  Lista L;
  Nodo **pCurr;
  int n;
  float f;
  int res;

  pCurr = &L;

  res = fscanf(fp, "%d:%f\n", &n, &f);
  while (res != EOF)
  {
    *pCurr = malloc(sizeof(Nodo));
    ((*pCurr)->dato).n = n;
    ((*pCurr)->dato).f = f;
    pCurr = &(*pCurr)->next;
    res = fscanf(fp, " %d:%f", &n, &f);
  }
  *pCurr = NULL;

  return L;
}

int main()
{
  FILE *fp = fopen("files/f1a.txt", "r");
  Lista L = CreaLista(fp);
  Nodo *curr;
  curr = L;
  for (curr = L; curr != NULL; curr = curr->next)
  {
    printf("%d\t%f\n", curr->dato.n, curr->dato.f);
  }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int info;
  struct _node *prox;
  struct _node *prec;
} Elem;

typedef Elem *Lista;

// Lista non ordinata
// Deve essere ricorsiva
// Cancella elemento tc el->info == n
Lista CancellaElemento(Lista l, int n)
{
  if(l->info == n)
  {
    // Cancella elemento
    // Prec punta a prox
    // Prox punta a prec
    // free(Elem)
    Elem *prec = l->prec;
    Elem *prox = l->prox;
    prec->prox = prox;
    prox->prec = prec;
    free(l);
    return prox;

    // Ritorna lista
  }
  CancellaElemento(l->prox, n);
}

int main()
{
}
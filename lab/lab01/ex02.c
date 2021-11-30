/*
  Scrivere un programma C che legge da tastiera tre numeri interi,
  e verifica se è possibile che essi siano le lunghezza dei tre lati
  di un triangolo: ciò richiede che ognuno dei tre sia minore della
  somma degli altri due. Se i tre interi sono le lunghezze dei lati
  di un triangolo, il programma stampa a schermo a quale delle seguenti
  categorie appartiene il triangolo:
  - equilatero (tre lati uguali)
  - isoscele (due lati hanno lunghezze uguali)
  - scaleno (tutti i lati di lunghezze differenti)
  In caso contrario,  il programma visualizza un messaggio di errore e termina.
  Esempio di esecuzione:
  Inserisci lunghezza del primo lato: 2
  Inserisci lunghezza del secondo lato: 3
  Inserisci lunghezza del terzo lato: 4
  Il triangolo è scaleno.
*/

#include <stdio.h>

int main()
{
  int a, b, c;
  printf("Inserisci lunghezza del primo lato: ");
  scanf("%d", &a);
  printf("Inserisci lunghezza del secondo lato: ");
  scanf("%d", &b);
  printf("Inserisci lunghezza del terzo lato: ");
  scanf("%d", &c);
  if (a < b + c && b < a + c && c < a + b)
  {
    printf("Il triangolo è ");
    if (a == b && a == c && b == c)
      printf("equilatero");
    else if (a != b && a != c && b != c)
      printf("scaleno");
    else
      printf("isoscele");
    printf(".\n");
  }
  else
  {
    printf("Non è un triangolo.\n");
  }
}
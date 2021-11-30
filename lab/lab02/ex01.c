/*
Scrivere   un   programma   C   che   legge   da   tastiera   una   sequenza   di   interi   positivi,   terminata   dal   valore   0,   determina   i   valori massimo e minimo tra quelli inseriti e li stampa a video. La sequenza può essere vuota (nel caso in cui il primo elemento inserito è pari a 0): in questo caso il programma deve visualizzare il messaggio “Nessun numero inserito.”.

Esempio di esecuzione: Inserisci un numero della sequenza (0 per terminare): 7
Inserisci un numero della sequenza (0 per terminare): 2

Inserisci un numero della sequenza (0 per terminare): 4
Inserisci un numero della sequenza (0 per terminare): 0
Valore massimo: 7 Valore minimo: 2

Altro esempio di esecuzione:
Inserisci un numero della sequenza (0 per terminare):0
Nessun numero inserito.
*/

#include <stdio.h>
#define MAX 30

int main()
{
  typedef struct
  {
    int N;
    int arr[MAX];
  } ListaSequenziale;

  ListaSequenziale lista;
  int curr;
  int min = __INT_MAX__;
  int max = 0;
  lista.N = 0;
  do
  {
    printf("Inserisci un numero della sequenza (0 per terminare): ");
    scanf("%d", &curr);
    if (curr != 0)
    {
      if(curr > max)
        max = curr;
      if(curr < min)
        min = curr;
      lista.arr[lista.N] = curr;
      lista.N++;
    }
  } while (curr != 0);

  printf("Valore massimo: %d\n", max);
  printf("Valore minimo: %d\n", min);
}
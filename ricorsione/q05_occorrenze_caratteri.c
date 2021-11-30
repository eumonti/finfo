/*
  Una Parola è rappresentata come una stringa di al più 20 caratteri
  compreso il carattere di terminazione.
  La ListaOccorrenze, associata a una Parola, è una lista sequenziale -di al
  più 19 elementi- ognuno dei quali contiene un carattere facente parte
  della parola e il numero di volte in cui questo carattere compare nella
  parola.

  Si definiscano il tipo Parola e il tipo ListaOccorrenze. Si scriva poi una <
  ricorsiva che, ricevendo in ingresso una Parola, costruisca la
  ListaOccorenze associate alla parola ricevuta in ingresso. L’ordine con
  cui i vari caratteri devono essere posizionati nella ListaOccorrenze
  deve essere lo stesso con cui essi compaiono per la prima volta nella
  Parola.
  Ad esempio:
  la ListaOccorrenze associata alla parola ordini è |5, [‘o’,1] [‘r’,1]
  [‘d’,1] [‘i’,2] [‘n’,1] [*,*] [*,*] … [*,*]|
  mentre la ListaOccorrenze associata alla parola amaca è |3, [‘a’,3]
  [‘m’,1] [‘c’,1] [*,*] [*,*] … [*,*] |.
*/

#include <stdio.h>

typedef enum
{
  false,
  true
} bool;

typedef char Parola[20];

typedef struct
{
  char ch;
  int number; // Number of times the ch occurs in Parola
} Occorrenza;

typedef struct
{
  int N;
  Occorrenza arr[19];
} ListaOccorrenze;

void stampaListaOccorrenze(ListaOccorrenze l)
{
  int i;
  for (i = 0; i < l.N; i++)
  {
    printf("Char %c occurs %d times.\n", l.arr[i].ch, l.arr[i].number);
  }
}

void costruisciListaOccorrenze(Parola p, ListaOccorrenze *pLista)
{
  // Last char, return
  if (*p == '\0')
    return;

  // Check if *p is in lista
  //  if not found, add it as an Occorrenza
  //  if found increment counter
  int i;
  bool found = false;
  for (i = 0; i < pLista->N && !found; i++)
  {
    if (*p == pLista->arr[i].ch)
    {
      found = true;
      pLista->arr[i].number++;
    }
  }
  if (!found)
  {
    // didn't find it, make Occorrenza
    Occorrenza o;
    o.ch = *p;
    o.number = 1;
    // Add o to *pLista
    pLista->arr[pLista->N++] = o;
  }

  // Repeat for next char in p
  costruisciListaOccorrenze(p + 1, pLista);
}

int main()
{
  ListaOccorrenze output;
  output.N = 0;
  costruisciListaOccorrenze("cipollal", &output);
  stampaListaOccorrenze(output);
}
#include <stdio.h>
#define BASE 4
#define MAX_LEN 100

typedef struct
{
  int cifre[MAX_LEN];
  int n;
  int inizioPeriodo;
} Rappresentazione;

/* Una Base di numerazione è definita tramite una primitiva #define. Si scriva una procedura
void che (i) riceve in ingresso un intero num, un intero den > num, e (ii) restituisce una rappresentazione in
base Base del numero frazionario num/den. La rappresentazione da restituire è una struct che contiene la
sequenza di cifre intere, il numero effettivo di tali cifre, l'indice che indica la posizione della prima cifra del
periodo nella sequenza. La sequenza di cifre si arresta (i) quando vengono occupate tutte le cifre disponibili
o (ii) quando non vi sono cifre significative da aggiungere, poiché le successive cifre sarebbero tutte nulle, o
(iii) quando viene completato il periodo.
 */

Rappresentazione Converti(int num, int den)
{
  Rappresentazione res;
  int i, j;
  int resti[MAX_LEN];
  int currNum; // Numeratore corrente
  int parteIntera;
  int resto;

  res.inizioPeriodo = -1;
  i = 0;
  currNum = num;
  while (i < MAX_LEN && currNum > 0)
  {
    parteIntera = currNum * BASE / den;
    resto = currNum * BASE % den;
    resti[i] = resto;
    /* Verifica se ho già visto questo resto. Se sì, il numero è periodico */
    for (j = 0; j < i; j++) // Itera resti[]
    {
      if (resti[j] == resto) // Numero periodico
      {
        printf("Trovato periodo che inizia in posizione %d.\n", j);
        res.inizioPeriodo = j;
        return res;
      }
    }
    res.cifre[res.n] = parteIntera;
    res.n++;
    currNum = resto;

    i++;
  }
  return res;
}

int main()
{
  int i;
  Rappresentazione r = Converti(10, 2034);
  // Rappresentazione r = FrazionarioPeriodico(3, 32);
  printf("0.");
  for (i = 0; i < r.n; i++)
  {
    printf("%d", r.cifre[i]);
  }
  printf("\n");
}
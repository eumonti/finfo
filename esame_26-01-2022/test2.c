// Si scriva una funzione ricorsiva che, ricevendo due stringhe (un
// testo lungo e una breve stringa), verifica se la stringa è presente nel testo
// e, in caso affermativo, restituisce il puntatore alla posizione nel testo
// dove è stata trovata la stringa; la funzione deve restituire NULL se la
// stringa non è presente nel testo

#include <stdlib.h>
#include <stdio.h>

char *cerca(char *S, char *T)
{
  if (*S == '\0')
    return T;
  if (*T == '\0')
    return NULL;

  if (*S == *T)
  {
    if (cerca(S + 1, T + 1) == T + 1)
      return T;
  }
  return cerca(S, T + 1);
}

int main()
{
  char *stringa = "cioccolato";
  char *testo = "questoeiltesto in cui devo cioccolato cercare la stringa ciao e buonanotte";
  printf("%s\n", cerca(stringa, testo));
}
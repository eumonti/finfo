/*
 * Scrivere un sottoprogramma ricorsivo che ricevuto in ingresso un numero
 * intero restituisca la cifra più alta della sua rappresentazione decimale.
 * Ad es., se il valore ricevuto in ingresso è milleduecentotrentadue (1232) il
 * sottoprogramma restituisce 3.
 */

#include <stdio.h>

int cifraMassima(int num)
{
  if (num / 10 == 0)
    return num;

  int tmpMax = cifraMassima(num / 10);
  return (tmpMax > num % 10) ? (tmpMax) : (num % 10);
}

int main()
{
  printf("%d\n", cifraMassima(1238822));
}
/*
E’ dato un intero N definito tramite una direttiva define. Si
scriva una funzione ricorsiva che, ricevendo in ingresso una stringa e un
intero k inizialmente posto uguale a 0, restituisce 1 se la stringa contiene
almeno N caratteri minuscoli consecutivi, e restituisce 0 altrimenti.
*/

#include <stdio.h>

#define N 3
typedef enum
{
  false,
  true
} bool;

bool find(char *s, int len)
{
  if (*s == '\0')
    return false;
  if (len >= N)
    return true;

  if (*s >= 'a' && *s <= 'z')
    return find(s + 1, len + 1);
  else // reset len to 0 (found caps char)
    return find(s + 1, 0);
}

int main()
{
  char *string = "ciasoAjfdJSJFnfnAjf";
  find(string, 0) ? printf("Trovati %d caratteri minuscoli consecutivi.\n", N) : printf("Non trovati.\n");
}
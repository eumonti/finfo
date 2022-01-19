#include <stdio.h>

// Calcola lunghezza e verifica se è periodica
// Se periodica:
//    Stampa la sequenza periodica
//    Restituisci 1
// Altrimenti:
//    Stampa avviso
//    Restituisci 0

void printString(char *string, int len)
{
  int i;
  for (i = 0; i < len; i++)
  {
    printf("%c", string[i]);
  }
  printf(".\n");
}

int checkPeriodP(char *string, int P, int len)
{
  int i;
  for (i = 0; i < len - P; i++)
  {
    if (string[i] != string[i + P])
    {
      return 0;
    }
  }
  return 1;
}

int fun(char *string)
{
  int len;
  int P;
  int iniz;

  len = 0;
  while (string[len] != '\0')
    len++;

  for (iniz = 0; iniz < len; iniz++)
  {
    for (P = 1; P <= (len - iniz) / 2; P++)
    {
      if (checkPeriodP(string + iniz, P, len - iniz))
      {
        // Found
        printf("Sequenza ripetuta: ");
        printString(string + iniz, P);
        return P;
      }
      // Go forth
    }
  }
  printf("Non trovata periodicità.\n");
  return 0;
}

int main()
{
  char *string = "quipartepartepart";
  int result = fun(string);
  result ? printf("Stringa periodica con P=%d.\n", result) : printf("Stringa non periodica.\n");
}
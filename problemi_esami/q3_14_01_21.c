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

int recursiveFun(char *string)
{
  int len;
  int P;
  int i;
  int br;

  if (*string == '\0')
  {
    printf("Non trovata periodicità.\n");
    return 0;
  }

  len = 0;
  while (string[len] != '\0')
    len++;

  for (P = 1; P <= len / 2; P++)
  {
    br = 0;
    for (i = 0; i < len - P && br == 0; i++)
    {
      if (string[i] != string[i + P])
      {
        br = 1;
      }
    }
    if (br == 0)
    {
      printf("Sequenza ripetuta: ");
      for(i = 0; i < P; i++)
        printf("%c", string[i]);
      printf("\n");
      return P;
    }
  }

  return recursiveFun(string + 1);
}

int main()
{
  char *string = "quipartepausapartepar";
  // int result = fun(string);
  int result = recursiveFun(string);
  result ? printf("Stringa periodica con P=%d.\n", result) : printf("Stringa non periodica.\n");
}
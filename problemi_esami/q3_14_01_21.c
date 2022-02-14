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
      for (i = 0; i < P; i++)
        printf("%c", string[i]);
      printf("\n");
      return P;
    }
  }

  return recursiveFun(string + 1);
}

int caglioti(char *string)
{
  int len;
  int trovato;
  int T;
  int cont;
  int max;
  int i;
  char *punt;

  for (len = 0; string[len] != '\0'; len++)
    ;

  trovato = 0;
  T = len / 2;
  while (T > 0 && trovato == 0)
  {
    cont = 0;
    max = cont;
    for (i = 0; i < len - T; i++)
      if (string[i + T] == string[i])
      {
        cont++;
        if (cont > max)
        {
          max = cont;
          punt = string + i - max + 1;
        }
      }
      else
        cont = 0;
    if (max >= T)
      trovato = 1;
    else
      T--;
  }
}

int TrovaPeriodo(char *string)
{
  int len, periodo;
  int i;
  int inizio;
  int br;

  len = 0;
  while (string[len] != '\0')
    len++;

  for (periodo = 1; periodo < len / 2; periodo++)
  {
    inizio = -1;
    br = 0;
    for (i = 0; i < len - periodo && !br; i++)
    {
      if (string[i] == string[i + periodo])
      {
        if (inizio == -1)
          inizio = i;
      }
      else if (inizio != -1)
      {
        br = 1;
      }
    }

    if (!br && inizio != -1)
    {
      printf("Periodo: ");
      printString(string + inizio, periodo);
      return periodo;
    }
  }
  printf("Non periodica\n");
  return 0;
}

int main()
{
  char *string = "quipartepausapartepar";
  // int result = fun(string);
  int result = TrovaPeriodo(string);
  result ? printf("Stringa periodica con P=%d.\n", result) : printf("Stringa non periodica.\n");
}
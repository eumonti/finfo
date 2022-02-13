#include <stdio.h>

int main()
{
  // Legge da tastiera 4 caratteri diversi tra loro e li memorizza in un array
  int i;
  char arr[4];
  char c;
  FILE *f;
  int esito;
  for (i = 0; i < 4; i++)
  {
    scanf(" %c", &arr[i]);
  }

  // Apre un file chiamato "elenco" contenuto nella directory del programma eseguibile
  f = fopen("elenco", "r");

  // Ricerca all'interno del file i 4 caratteri

  esito = 1;
  for (i = 0; i < 4 && esito == 1; i++)
  {
    // fscanf(f, " %c, &c);
    c = fgetc(f);
    // while (!feof(f) && arr[i] != c)
    while (c != EOF && arr[i] != c)
    {
      // fscanf(f, " %c", &c);
      c = fgetc(f);
    }
    if (arr[i] != c)
    {
      esito = 2;
    }
    else
    {
      rewind(f);
    }
  }

  printf("%d\n", esito);
}
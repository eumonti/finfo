/*
Si scriva un programma C che (i) legge da tastiera un intero positivo di valore compreso tra 1 e
99 (si supponga di non dover effettuare controlli sul corretto valore del numero letto), (ii) crea un file di
testo di nome “MultipliDiXY.txt”, dove XY sono le cifre decimali dell’intero letto (ad esempio “72” per 72 e
“08” per 8), (iii) scrive sul file aperto i primi dieci multipli dell’intero letto intervallati da uno spazio, e (iv)
chiude il file.
*/
#include <stdio.h>

int main()
{
  FILE *fp;
  int n;
  char fileName[50] = "files/MultipliDiXY.txt";
  int i, j;
  i = 0;
  while (fileName[i] != 'X')
    i++;

  scanf("%d", &n);
  fileName[i] = (n / 10) + '0';
  fileName[i + 1] = (n % 10) + '0';

  fp = fopen(fileName, "w");
  if (fp == NULL)
  {
    fprintf(stderr, "Errore apertura file.\n");
    return -1;
  }
  for (j = 2; j < 12; j++)
  {
    fprintf(fp, "%d ", n * j);
  }

  fclose(fp);
}
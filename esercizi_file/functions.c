#include <stdio.h>

/*
Funzioni utili:

int fscanf(
   FILE *stream,
   const char *format [,
   argument ]...
)
Restituisce il numero di campi convertiti ed assegnati correttamente.
Se si verifica un errore o se viene raggiunta la fine del flusso di file
prima della prima conversione, il valore restituito è EOF.

int fprintf(
   FILE *stream,
   const char *format [,
   argument ]...
);
Restituisce il numero di byte scritti

*/
int main()
{
  FILE *fp;
  int ret, n;
  /* Leggi dati da file con fscanf */
  /*
  file.txt:
  1
  2
  3
  4
  5
  */
  fp = fopen("file.txt", "r");
  ret = fscanf(fp, "%d\n", &n);
  while (ret != EOF)
  {
    printf("%d\n", n);
    ret = fscanf(fp, "%d\n", &n);
  }
}
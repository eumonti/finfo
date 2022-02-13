/*
Un problema da linea di comando in cui inserisci il nome di un file .txt e una stringa di caratteri e crea il file inserendoci all'interno la stringa di caratteri
*/
#include <stdio.h>

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    printf("Numero di argomenti errato.\n");
    return -1;
  }
  FILE *fp;
  fp = fopen(argv[1], "w");
  fprintf(fp, "%s", argv[2]);
}

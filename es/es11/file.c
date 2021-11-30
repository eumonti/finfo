#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Wrong arguments.");
    return -1;
  }
  FILE *fp;
  char c;
  if ((fp = fopen(argv[1], "r")) == NULL)
    return -2;

  while ((c = getc(fp)) != EOF)
    putchar(c);

  fclose(fp);
}
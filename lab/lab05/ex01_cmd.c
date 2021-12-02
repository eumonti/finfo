#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    printf("Pochi argomenti\n");
    return -1;
  }
  if (argc > 4)
  {
    printf("Troppi argomenti");
    return -1;
  }

  printf("%s\n", argv[1]);

  if (strcmp(argv[1], "-a") == 0)
  {
    printf("Addizione: ");
    printf("%d\n", atoi(argv[2]) + atoi(argv[3]));
  }
  else if (strcmp(argv[1], "-s") == 0)
  {
    printf("Sottrazione: ");
    printf("%d\n", atoi(argv[2]) - atoi(argv[3]));
  }
  else if (strcmp(argv[1], "-m") == 0)
  {
    printf("Moltiplicazione: ");
    printf("%d\n", atoi(argv[2]) * atoi(argv[3]));
  }
  else
  {
    printf("Argomento inserito non valido");
    return -1;
  }
}
#include <stdio.h>
#include <string.h>

void printLowerCase(char *string)
{
  int i = 0;
  int len = strlen(string);
  for (i = 0; i < len; i++)
  {
    if (string[i] >= 'a') // it is lowercase
    {
      printf("%c", string[i]);
    }
    else
    {
      printf("%c", string[i] + ('a' - 'A')); // convert to lower
    }
  }
  printf("\n");
}

void printUpperCase(char *string)
{
  int i = 0;
  int len = strlen(string);
  for (i = 0; i < len; i++)
  {
    if (string[i] >= 'a') // it is lowercase
    {
      printf("%c", string[i] - ('a' - 'A'));
    }
    else
    {
      printf("%c", string[i]);
    }
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    printf("Pochi argomenti\n");
    return -1;
  }
  if (argc > 3)
  {
    printf("Troppi argomenti");
    return -1;
  }

  if (strcmp(argv[1], "-m") == 0)
  {
    printf("Converto in minuscolo: ");
    printLowerCase(argv[2]);
  }
  else if (strcmp(argv[1], "-M") == 0)
  {
    printf("Converto in maiuscolo: ");
    printUpperCase(argv[2]);
  }
}
#include <stdio.h>

#define CAPIENZA 10
#define TERMINATORE '0'

typedef enum
{
  false,
  true
} bool;

typedef struct
{
  int N;
  char arr[CAPIENZA];
} TipoL;

int main()
{
  TipoL Lista;
  int i;
  char c;
  bool end = false;

  Lista.N = 0;
  while (Lista.N < CAPIENZA && !end)
  {
    printf("Carattere %d: ", Lista.N);
    scanf(" %c", &c);
    while (c != TERMINATORE && !(c >= 'a' && c <= 'z'))
    {
      printf("Il carattere inserito non è valido ed è stato ignorato.\n");
      printf("Carattere %d: ", Lista.N);
      scanf(" %c", &c);
    }

    if (c != TERMINATORE)
      Lista.arr[Lista.N++] = c;
    else
    {
      printf("Inserito carattere terminatore. Fine sequenza.");
      end = true;
    }
  }

  printf("\nCaratteri immessi: ");
  for (i = 0; i < Lista.N; i++)
  {
    printf("%c ", Lista.arr[i]);
  }
  printf("\n");
  return 0;
}
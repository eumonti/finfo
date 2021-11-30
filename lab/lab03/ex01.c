#include <stdio.h>

#define CAPIENZA 10

typedef struct
{
  int N;
  char arr[CAPIENZA];
} TipoL;

int main()
{
  TipoL Lista;
  int i;
  for (Lista.N = 0; Lista.N < CAPIENZA; Lista.N++)
  {
    printf("Carattere %d: ", Lista.N);
    scanf(" %c", &Lista.arr[Lista.N]);
  }
  printf("\nCaratteri immessi: ");
  for (i = 0; i < Lista.N; i++)
  {
    printf("%c ", Lista.arr[i]);
  }
  printf(".\n");
  return 0;
}
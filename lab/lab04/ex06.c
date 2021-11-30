#include <stdio.h>
#include <stdlib.h>

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

char Minimo(TipoL list)
{
  int i;
  char min = 'z';
  for (i = 0; i < list.N; i++)
  {
    if (list.arr[i] < min)
      min = list.arr[i];
  }
  return min;
}

bool find(char c, TipoL list);
void printList(TipoL list);
void EseguiInput(TipoL *list);

int main()
{
  TipoL Lista;
  EseguiInput(&Lista);
  printList(Lista);
  if (Lista.N > 0)
    printf("%c\n", Minimo(Lista));
  return 0;
}

bool find(char c, TipoL list)
{
  int i;
  for (i = 0; i < list.N; i++)
  {
    if (list.arr[i] == c)
      return true;
  }
  return false;
}

void printList(TipoL list)
{
  int i;
  printf("\nCaratteri immessi: ");
  for (i = 0; i < list.N; i++)
  {
    printf("%c ", list.arr[i]);
  }
  printf("\n");
}

void EseguiInput(TipoL *list)
{
  char tmpChar;
  bool isValidChar = true;
  bool isAlreadyPresent = false;

  for (list->N = 0; list->N < CAPIENZA; list->N++)
  {
    do
    {
      printf("Carattere %d: ", list->N);
      scanf(" %c", &tmpChar);
      isValidChar = (tmpChar >= 'a' && tmpChar <= 'z');
      isAlreadyPresent = find(tmpChar, *list);
      if (!isValidChar)
        printf("Il carattere inserito non è valido ed è stato ignorato. Immetti un altro carattere.\n");
      if (isAlreadyPresent)
        printf("Il carattere è già presente ed è stato ignorato. Immetti un altro carattere.\n");
    } while (!isValidChar || isAlreadyPresent);

    if (tmpChar != TERMINATORE)
      list->arr[list->N] = tmpChar;
    else
    {
      printf("Inserito carattere terminatore. Fine sequenza.");
      return;
    }
  }
}
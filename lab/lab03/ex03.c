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

bool find(char c, TipoL list);
void printList(TipoL list);
void getUserInput(TipoL *list);

int main()
{
  TipoL Lista;
  getUserInput(&Lista);
  printList(Lista);
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

void getUserInput(TipoL *list)
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
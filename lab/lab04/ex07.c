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

bool find(char c, TipoL list);
void printList(TipoL list);
void EseguiInput(TipoL *list);
char Minimo(TipoL list, char Soglia);
TipoL Ordina(TipoL list);

int main()
{
  TipoL Lista;
  EseguiInput(&Lista);
  printList(Lista);
  if (Lista.N > 0)
  {
    printf("%c\n", Minimo(Lista, 'd'));
    TipoL ListaOrdinata = Ordina(Lista);
    printList(ListaOrdinata);
  }
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
  list->N = 0;
  while (list->N < CAPIENZA)
  {
    printf("Carattere %d: ", list->N + 1);
    scanf(" %c", &tmpChar);
    if (tmpChar == TERMINATORE)
    {
      printf("Inserito carattere terminatore. Fine sequenza.");
      return;
    }
    if (!(tmpChar >= 'a' && tmpChar <= 'z'))
      printf("Il carattere inserito non è valido ed è stato ignorato. Immetti un altro carattere.\n");
    else if (find(tmpChar, *list))
      printf("Il carattere è già presente ed è stato ignorato. Immetti un altro carattere.\n");
    else
      list->arr[list->N++] = tmpChar;
  }
}

// void EseguiInput(TipoL *list)
// {
//   char tmpChar;
//   bool isValidChar = true;
//   bool isAlreadyPresent = false;

//   for (list->N = 0; list->N < CAPIENZA; list->N++)
//   {
//     do
//     {
//       printf("Carattere %d: ", list->N + 1);
//       scanf(" %c", &tmpChar);
//       isValidChar = (tmpChar >= 'a' && tmpChar <= 'z');
//       isAlreadyPresent = find(tmpChar, *list);
//       if (!isValidChar)
//         printf("Il carattere inserito non è valido ed è stato ignorato. Immetti un altro carattere.\n");
//       if (isAlreadyPresent)
//         printf("Il carattere è già presente ed è stato ignorato. Immetti un altro carattere.\n");
//     } while (tmpChar != TERMINATORE && (!isValidChar || isAlreadyPresent));

//     if (tmpChar == TERMINATORE)
//     {
//       printf("Inserito carattere terminatore. Fine sequenza.");
//       return;
//     }
//     list->arr[list->N] = tmpChar;
//   }
// }

char Minimo(TipoL list, char Soglia)
{
  int i;
  char min = 'z' + 1;
  for (i = 0; i < list.N; i++)
  {
    if (list.arr[i] < min && list.arr[i] > Soglia)
      min = list.arr[i];
  }
  if (min == 'z' + 1)
    return TERMINATORE;
  return min;
}

TipoL Ordina(TipoL list)
{
  TipoL orderedList;
  orderedList.N = 0;
  orderedList.arr[orderedList.N] = Minimo(list, 'a' - 1);

  for (orderedList.N = 1; orderedList.N < list.N; orderedList.N++)
  {
    orderedList.arr[orderedList.N] = Minimo(list, orderedList.arr[orderedList.N - 1]);
  }
  return orderedList;
}
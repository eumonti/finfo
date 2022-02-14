/*
Un array binario di 1000 interi, ciascuno dei quali può assumere
solamente i valori 0 o 1, può essere codificato usando la codifica Run Length Code (RLC) mediante
una lista sequenziale di valori interi, ciascuno dei quali rappresenta la lunghezza di una sequenza di
“0” consecutivi o di “1” consecutivi compresi nell’array. Si suppone che la codifica RLC di un array
cominci sempre –per convenzione- con il numero di “0” consecutivi che si trovano all’inizio
dell’array stesso. Si scriva una funzione che riceve in ingresso un array binario e restituisce la lista
sequenziale che contiene la sua codifica RLC. Ad esempio l’array
0000000111001111000000111110… ha codifica (7, 3, 2, 4, 6, 5, …), mentre l’array
111001111000000111110… ha codifica (0, 3, 2, 4, 6, 5, …).
*/
#include <stdio.h>
#include <stdlib.h>

#define LEN 5
#define MAX_LEN 100

typedef struct _node
{
  int info;
  struct _node *prox;
} ElemLista;
typedef ElemLista *ListaDinamica;

typedef struct lista
{
  int n;
  int arr[MAX_LEN];
} Lista;

Lista RLC(int binArr[LEN])
{
  Lista res;
  int currDigit, currCount;
  int i;

  res.n = 0;
  currDigit = 0;
  currCount = 0;
  for (i = 0; i < LEN; i++)
  {
    if (binArr[i] == currDigit)
    {
      currCount++;
    }
    else
    {
      res.arr[res.n] = currCount;
      res.n++;
      currDigit = !currDigit;
      currCount = 1;
    }
  }
  res.arr[res.n] = currCount;
  res.n++;
  return res;
}

ListaDinamica RLC_linked_list(int arr[LEN])
{
  ListaDinamica L;
  ElemLista **pCurr;
  int i;
  int currDigit, currCount;
  currDigit = 0;
  currCount = 0;
  pCurr = &L;

  for (i = 0; i < LEN; i++)
  {
    if (arr[i] == currDigit)
      currCount++;
    else
    {
      currDigit = !currDigit;
      *pCurr = malloc(sizeof(ElemLista));
      (*pCurr)->info = currCount;
      pCurr = &(*pCurr)->prox;
      currCount = 1;
    }
  }
  *pCurr = malloc(sizeof(ElemLista));
  (*pCurr)->info = currCount;
  (*pCurr)->prox = NULL;
  return L;
}

int main()
{
  int arr[LEN] = {0, 1, 0, 1, 1};
  int i;
  // ListaDinamica L = RLC(arr);

  Lista res = RLC(arr);

  for (i = 0; i < res.n; i++)
  {
    printf("%d ", res.arr[i]);
  }
  printf("\n");
  // ElemLista *curr;
  // for (curr = L; curr != NULL; curr = curr->prox)
  // {
  //   printf("%d ", curr->info);
  // }
  // printf("\n");
}

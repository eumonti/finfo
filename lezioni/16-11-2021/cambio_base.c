/*
  Scrivi una funzione ricorsiva per cambiare base.

  La funzione restituisce una lista sequenziale delle cifre e accetta come argomenti il numero e la base

*/

#include <stdio.h>

#define MAX 30

typedef struct
{
  int N;
  int arr[30];
} List;

void printList(List l)
{
  for (size_t i = 0; i < l.N; i++)
  {
    printf("%d ", l.arr[i]);
  }
  printf("\n");
}

List cambiaBase(int n, int b)
{
  List num;
  if (n >= b)
  {
    num = cambiaBase(n / b, b);
    num.arr[num.N++] = n % b; // Aggiungi ultimo elemento
  }
  else
  {
    num.arr[0] = n;
    num.N = 1;
  }
  return num;
}

List Converti(int N, int b)
{
  List L;
  if (N < b)
  {
    L.arr[0] = N;
    L.N = 1;
  }
  else
  {
    L = Converti(N / b, b);
    L.arr[L.N] = N % b;
    L.N++;
  }
  return (L);
}

int main()
{
  int num = 25;
  List res = Converti(num, 2);
  printList(res);
}
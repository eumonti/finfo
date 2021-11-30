#include <stdio.h>

#define LEN 30

typedef struct
{
  int N;
  int arr[LEN];
} Lista;

int main()
{
  Lista l;
  l.N = 0;
  l.arr[l.N++] = 10;
}
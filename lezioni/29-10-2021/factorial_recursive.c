#include <stdio.h>

int fact(int n)
{
  if (n == 0)
    return 1;
  return n*fact(n - 1);
}

int main()
{
  int number;
  scanf("%d", &number);
  printf("%d\n", fact(number));
}
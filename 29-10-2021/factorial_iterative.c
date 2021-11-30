#include <stdio.h>

int main()
{
  int n;
  int res = 1;
  scanf("%d", &n);
  while (n > 1)
  {
    res *= n;
    n--;
  }
  printf("%d\n", res);
}
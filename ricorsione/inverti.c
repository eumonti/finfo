#include <stdio.h>

#define TAPPO -1

void inverti()
{
  int n;
  scanf("%d", &n);
  if (n == TAPPO)
    return;
  inverti();
  printf("%d\n", n);
}

int main()
{
  inverti();
}
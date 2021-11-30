#include <stdio.h>

// returns nth number in fibonacci sequence (starting from 0)
int fib(int n)
{
  if(n == 0)
    return n;
  return n + fib(n - 1);
}

int main()
{
  int res = fib(10);
  printf("%d", res);
}
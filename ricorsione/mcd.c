#include <stdio.h>

int mcd(int n, int m)
{
  int tmp;
  if (n < m)
  {
    tmp = n;
    n = m;
    m = tmp;
  }
  // n grater than m
  if (n % m == 0)
    return m;
  return mcd(m, n % m);
}

int main()
{
  printf("%d\n", mcd(238, 342));
}
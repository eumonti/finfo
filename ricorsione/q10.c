#include <stdio.h>

// Dalla più significativa alla meno
void stampaCifre(int n, int base)
{
  if (n / base == 0)
  {
    printf("%d\n", n);
    return;
  }
  stampaCifre(n / base, base);
  printf("%d\n", n % base);
}

int main()
{
  stampaCifre(345, 10);
}
#include <stdio.h>

int main()
{
  unsigned int x = __UINT32_MAX__;
  float cast = (float)x;
  printf("%u\n", x);
  printf("%f\n", cast);
  printf("%lu", sizeof(cast));
}
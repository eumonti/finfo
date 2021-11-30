/*
  Tower of hanoi (recursive algorithm)
  1. Shift 'n-1' disks from 'A' to 'B'.
  2. Shift last disk from 'A' to 'C'.
  3. Shift 'n-1' disks from 'B' to 'C'.
*/

#include <stdio.h>

void towerOfHanoi(int n, const char from, const char to, const char aux)
{
  if (n == 1)
  {
    printf("Move %c to %c\n", from, to);
    return;
  }
  towerOfHanoi(n - 1, from, aux, to);
  printf("Move %c to %c\n", from, to);
  towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
  int n = 4;                      // number of disks
  towerOfHanoi(n, 'A', 'B', 'C'); // A, B, C are the towers
  return 0;
}
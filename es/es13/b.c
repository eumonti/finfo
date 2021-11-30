#include <stdlib.h>

int main()
{
  int *first = malloc(sizeof(int));
  int *second = first;

  free(first);
  free(second);

}
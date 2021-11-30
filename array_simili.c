#include <stdio.h>

#define L1 10
#define L2 8

int main()
{
  int arr1[L1] = {1, 9, 5, 6, 4, 2, 3, 7, 8, 0};
  int arr2[L2] = {10, 2, 14, 1, 15, 16, 18, 3};
  int i, j;
  int index_of_common_element = 0;
  for (i = 0; i < L1; i++)
  {
    for (j = 0; j < L2; j++)
    {
      if (arr2[j] == arr1[i])
      {
        if (j < index_of_common_element)
        {
          printf("Eh noeh\n");
          return 0;
        }
        index_of_common_element = j;
      }
    }
  }
  printf("Eh sieh\n");
  return 0;
}

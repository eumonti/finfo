#include <stdio.h>

#define MAX 100

int main()
{
  struct
  {
    int len;
    int arr[MAX];
  } code;
  code.len = 0;
  int i;
  int input[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1};
  int inputLen = sizeof(input) / sizeof(input[0]);

  int last = 0;
  int counter = 0;
  for (i = 0; i < inputLen; i++)
  {
    if (input[i] == last)
    {
      counter++;
    }
    else
    {
      code.arr[code.len] = counter;
      code.len++;
      last = input[i];
      counter = 1;
    }
  }
  code.arr[code.len] = counter;
  code.len++;
  for (i = 0; i < code.len; i++)
  {
    printf("%d ", code.arr[i]);
  }
  printf("\n");
}
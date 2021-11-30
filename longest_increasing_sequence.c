#include <stdio.h>

int main()
{
  int arr[] = {1, 2, 3, 4, 12, 5, 4, 1, 4, 6, 32, 65, 127, 4, 2, 8, 9, 10, 23, 25, 27, 28, 29, 30, 213};
  int length = sizeof(arr) / sizeof(arr[0]);
  int i;
  int maxlength = 0;
  int currlength = 1;
  int start = -1;
  for (i = 1; i < length; i++)
  {
    if (arr[i] >= arr[i - 1])
    {
      currlength++;
    }
    else if(currlength > maxlength)
    {
      maxlength = currlength;
      start = i - maxlength;
      currlength = 1;
    }
  }
  if(currlength > maxlength)
  {
    maxlength = currlength;
    start = i - maxlength;
  }

  printf("Start: %d, Length: %d\n", start, maxlength);
}
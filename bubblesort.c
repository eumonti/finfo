#include <stdio.h>

// Bubblesort
void sort(int *arr, int len)
{
  int i, j;
  int temp;
  for (i = len - 1; i > 0; i--)
  {
    // Porta l'elemento più alto presente nella sequenza tra 0 e i in posizione i
    for (j = 1; j <= i; j++)
    {
      if (arr[j - 1] > arr[j])
      {
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void sort2(int *arr, int len)
{
  int i, j, tmp;
  for (i = 0; i < len; i++)
  {
    for (j = 0; j < len - i - 1; j++)
    {
      if (arr[j + 1] < arr[j])
      {
        // swap arr[j + 1] and arr[j]
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

void sort3(int *arr, int len)
{
  int i, j, tmp;
  for (i = 0; i < len; i++)
  {
    for (j = len - 1; j > i; j--)
    {
      if (arr[j] < arr[j - 1])
      {
        tmp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = tmp;
      }
    }
  }
}

int main()
{
  int i;
  int arr[] = {29, 12, 5, 68, 312, 9, 0, 2, 102};
  int len = sizeof(arr) / sizeof(arr[0]);
  sort3(arr, len);
  for (i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
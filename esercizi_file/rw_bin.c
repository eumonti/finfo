#include <stdio.h>

void printArray(int arr[], int len)
{
  int i;
  for (i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  FILE *fp;
  int arr[] = {1, 2, 3, 4, 5};
  fp = fopen("file-rw_bin/arr", "wb");
  if (fp == NULL)
  {
    fprintf(stderr, "Errore\n");
    return -1;
  }
  fwrite(arr, sizeof(arr), 1, fp);
  fclose(fp);

  fp = fopen("./file-rw_bin/arr", "rb");
  int arr2[5];
  fread(arr2, sizeof(arr2), 1, fp);
  printArray(arr2, sizeof(arr2)/sizeof(arr[0]));
  
  fclose(fp);

}
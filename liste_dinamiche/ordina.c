#include <stdio.h>
// #include "../lib/linkedlist_int.h"

// prev->curr->next->(next->next)
// Swap curr with next
// prev->next->curr->(next->next)

// Bubble sort

// 20->12->13->8->4->6->2->3->1->NULL
// void ordina(Node **pList)
// {
//   Node *curr1, *curr2;
//   while(curr1 != NULL)
//   {
//     while(curr2 != NULL)
//     {
//       if(curr1->data > curr2->data)
//       {
//         // Swap
//         curr2->next
//       }
//     }
//   }

// }

void bubbleSort(int *arr, int len)
{
  int tmp;
  int i, j;
  for (i = 0; i < len; i++)
  {
    for (j = 0; j < len - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

int main()
{
  // Node *list = getSequence("sequence2.txt");
  // ordina(&list);
  // printList(list);
  int arr[] = {20, 12, 13, 8, 4, 6, 2, 3, 1};
  int len = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, len);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
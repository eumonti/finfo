#include <stdio.h>

// Calcola lunghezza e verifica se è periodica
// Se periodica:
//    Stampa la sequenza periodica
//    Restituisci 1
// Altrimenti:
//    Stampa avviso
//    Restituisci 0
int fun(char *string)
{
  int len;
  int p;
  int i;

  len = 0;
  while (string[len] != '\0')
  {
    len++;
  }
  printf("%d\n", len);

  for (p = 0; p < len / 2; p++)
  {
    for(i = 0; i < len - p; i++)
    {
      if(string[i] != string[i + p])
      {
        
      }
    }
  }
}

int main()
{
}
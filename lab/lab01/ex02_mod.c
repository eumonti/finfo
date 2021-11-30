/*
  Una volta che il programma funziona correttamente, lo si modifichi per utilizzare lunghezze dei lati di tipo float.
*/

#include <stdio.h>

int main()
{
  float a, b, c;
  printf("Inserisci lunghezza del primo lato: ");
  scanf("%f", &a);
  printf("Inserisci lunghezza del secondo lato: ");
  scanf("%f", &b);
  printf("Inserisci lunghezza del terzo lato: ");
  scanf("%f", &c);
  if (a < b + c && b < a + c && c < a + b)
  {
    printf("Il triangolo è ");
    if (a == b && a == c && b == c)
      printf("equilatero");
    else if (a != b && a != c && b != c)
      printf("scaleno");
    else
      printf("isoscele");
    printf(".\n");
  }
  else
  {
    printf("Non è un triangolo.\n");
  }
}
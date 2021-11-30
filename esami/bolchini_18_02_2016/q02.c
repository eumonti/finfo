/*
Un numero n è detto "troncabile primo a sinistra" se n e tutti i numeri ottenuti rimuovendo successivamente la cifra più a sinistra sono primi. Scrivere il sottoprogramma lefttprime che ricevuto in ingresso un intero val restituisce 1 se il numero è troncabile primo a sinistra.
Esempio:
Ingresso:317
  317 è primo -> 17 è primo -> 7 è primo
Uscita:1
*/

#include <stdio.h>

int power(int num, int exp)
{
  int i;
  int result = 1;
  for (int i = 0; i < exp; i++)
    result *= num;
  return result;
}

int isPrime(int n)
{
  int i;
  for (i = 2; i <= n/2; i++)
  {
    if(n % i == 0)
      return 0;
  }
  return 1;  
}

int leftprime(int val)
{
  int i;
  int digits = 1;
  int tmp = val;
  while (tmp / 10 != 0)
  {
    tmp /= 10;
    digits++;
  }

  for (i = 0; i < digits; i++)
  {
    if (!isPrime(val % power(10, i)))
      return 0;
  }
  return 1;
}

int main()
{
  printf("%d", leftprime(349));
}
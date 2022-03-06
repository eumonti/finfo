#include <stdio.h>

#define MAX 30
#define BASE 8
#define DIM 3 * MAX

// numIn è in base 8
// numOut è numIn in base 2
void fun(char numIn[MAX + 1], char numOut[DIM + 1])
{
  int i, j;
  int cifreIn, cifreOut;
  int n;
  char arr[DIM + 1];
  int leadingZeros;

  cifreIn = 0;
  while (numIn[cifreIn] != '\0')
    cifreIn++;

  for (i = 0; i < cifreIn; i++)
  {
    n = numIn[i];
    for (j = 2; j >= 0; j--)
    {
      arr[3 * i + j] = '0' + n % 2;
      n /= 2;
    }
  }

  leadingZeros = 0;
  while (arr[leadingZeros] != '1')
    leadingZeros++;

  cifreOut = 3 * cifreIn - leadingZeros;
  for (i = 0; i < cifreOut; i++)
  {
    numOut[i] = arr[leadingZeros + i];
  }
  numOut[i] = '\0';
}

void C2()
{
}

void RappresentaC2(char s[MAX + 1], char r[DIM + 1])
{
  int i, j, k;
  int resto, quoziente;
  int numcifre;
  int last1;
  int intermedio[DIM];
  for (i = 0; i < MAX && s[i] != '\0'; i++)
  {
    quoziente = s[i] - '0';
    for (j = 3 * i + 2; j >= 3 * i; j--) /* 3 cifre per base B=8 */
    {
      intermedio[j] = quoziente % 2;
      quoziente = quoziente / 2;
    }
  }
  for (j = 0; j < 3 * i; j++)
    printf("%d", intermedio[j]);

  printf("\n");
  numcifre = 0;
  for (k = 0; k < j; k++)
  {
    if (numcifre == 0 && intermedio[k] == 1)
    {
      r[numcifre] = '0';
      numcifre++;
    }
    if (numcifre > 0)
    {
      r[numcifre] = '0' + intermedio[k];
      numcifre++;
    }
  }
  r[numcifre] = '\0';
  last1 = 0;
  for (j = numcifre - 1; j >= 0; j--)
  {
    if (last1 == 1)
    {
      if (r[j] == '0')
        r[j] = '1';
      else
        r[j] = '0';
    }
    if (r[j] == '1')
      last1 = 1;
  }
}

int main()
{
  char numOut[DIM + 1];
  RappresentaC2("172", numOut);
  printf(" %s\n", numOut);
}
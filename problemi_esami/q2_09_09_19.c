#include <stdio.h>

#define LUNGHEZZA_TESTO 16
#define IS_LOWERCASE(x) (x >= 'a' && x <= 'z')

int check(char testo[LUNGHEZZA_TESTO])
{
  char last = '.';
  int i = 0;
  while (i < LUNGHEZZA_TESTO)
  {
    if (IS_LOWERCASE(testo[i]))
    {
      if (i == 0 || !IS_LOWERCASE(testo[i - 1])) // start of word
      {
        if (last != '.' && last != testo[i])
          return 0;
        last = testo[i];
      }
    }
    i++;
  }
  return 1;
}

int main()
{
  char arr[] = ".A;addio.artu--";
  check(arr) ? printf("Yes\n") : printf("No\n");
}

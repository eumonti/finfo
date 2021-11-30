#include <stdio.h>

typedef enum
{
  false,
  true
} bool;

bool palindrome(char *start, char *end)
{
  if (end - start <= 2)
    return (*start == *end);
  if (*start == *end)
    return palindrome(start + 1, end - 1);
  return false;
}

bool palindrome_alt(char *start, char *end)
{
  if (*start != *end)
    return false;
  if(start >= end)
    return true;
  return palindrome_alt(start + 1, end - 1);
}

int main()
{
  char *string = "hannah";
  int str_size = 0;
  while (string[str_size] != '\0')
    str_size++;
  str_size--;
  palindrome_alt(string, string + str_size) ? printf("Yes") : printf("No");
}
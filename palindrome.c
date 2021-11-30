#include <stdio.h>

typedef enum
{
	false,
	true
} boolean;

boolean palindrome(char *string, int len)
{
	int i;
	for (i = 0; i < len / 2; i++)
	{
		if (string[i] != string[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

int stringlength(char *string)
{
	int i = 0;
	while (string[i] != '\0')
		i++;
	return i;
}

int main()
{

	char *string = "anaanna";
	int len = stringlength(string);	
	palindrome(string, len) ? printf("String is palindrome") : printf("String is not palindrome");
}

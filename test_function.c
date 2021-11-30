#include <stdio.h>

int i = 0;

float power(float base, float esponente)
{
	int i;
	float risultato = 1;
	for (i = 0; i < esponente; i++)
	{
		risultato *= base;
	}
	return risultato;
}

int main()
{
	printf("%f", power(2, 8));
}

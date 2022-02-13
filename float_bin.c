#include <stdio.h>

int main()
{
	union ufloat {
		float f;
		unsigned u;
	} u1;
	u1.f = -103.4;
	printf("%u\n", u1.u);
}

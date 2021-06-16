#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>


int is_palindrome(unsigned long n)
{
	unsigned long revn, rem, origin;

	revn = 0;
	origin = n;
	while (n != 0)
	{
		rem = n % 10;
		revn = revn * 10;
		revn += rem;
		n /= 10;
	}
	if (origin == revn)
		return (1);
	return (0);
}

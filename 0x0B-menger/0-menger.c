#include "menger.h"

/**
* menger - prints a 2d menger fractal of inputed level
* @level: the level of menger fractal
*/
void menger(int level)
{
	if (level >= 0)
	{
		if (level == 0)
		printf("#\n");

		if (level == 1)
		{
			printf("###\n# #\n###\n");
		}
	}
}

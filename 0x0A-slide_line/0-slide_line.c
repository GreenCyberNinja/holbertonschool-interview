#include "slide_line.h"

/**
 * slide_line - slides similar to 2048 game if the numbers equal they add
 * @line: line(array) to slide on
 * @size: size of the line(array)
 * @direction: the direction to slide in controlled by macros
 * Return: 0 on failure 1 on succes
*/
int slide_line(int *line, size_t size, int direction)
{
    	unsigned int i, slideSucces = 0, farSlide;

	if (line == NULL || size == 0 || direction > 1)
	{
		return (0);
	}
	if (size == 1)
	{
		return (1);
	}

	if (direction == SLIDE_LEFT)
	{
		farSlide = 0;
		for(i = 0; i < size; i++)
		{
			if (line[i] != 0)
				slideSucces += Lslide(line, i, size, &farSlide);
		}
	}
	if (direction == SLIDE_RIGHT)
	{
		farSlide = size - 1;
		for(i = size - 1; i > 0; i--)
		{
			if (line[i] != 0)
				slideSucces += Rslide(line, i, size, &farSlide);
		}
		if (line[i] != 0)
			slideSucces += Rslide(line, i, size, &farSlide);
	}
	return (1);
}

int Lslide(int *line, unsigned int start, size_t size, unsigned int *farSlide)
{
	unsigned int i = start;
	size = size;
	while (i > *farSlide)
	{
		i--;
		if (line[i] == 0 && !(i <= 0))
			continue;

		else if (line[i] == line[start])
		{
			if(*farSlide < i || *farSlide == 0)
			{
				line[i] += line[start];
				line[start] = 0;
				*farSlide = i;
				return (1);
			}
			break;
		}
		else
			break;

	}
	if (line[i] == 0 && i != start)
	{
		line[i] += line[start];
		line[start] = 0;
	}
	else if (i + 1 != start && line[i + 1] == 0)
	{
		line[i + 1] += line[start];
		line[start] = 0;
	}
	return (0);
}

int Rslide(int *line, unsigned int start, size_t size, unsigned int *farSlide)
{
	unsigned int i = start;
	while (i < *farSlide)
	{
		i++;
		if (line[i] == 0 && !(i >= size))
		{
			continue;
		}
		else if (line[i] == line[start])
		{
			if(*farSlide > i || *farSlide == size - 1)
			{
				line[i] += line[start];
				line[start] = 0;
				*farSlide = i;
				return (1);
			}
			break;
		}
		else
		{
			break;
		}
	}
	if (line[i] == 0 && i != start)
	{
		line[i] += line[start];
		line[start] = 0;
	}
	else if (i - 1 != start && line[i - 1] == 0)
	{
		line[i - 1] += line[start];
		line[start] = 0;
	}
	return (0);
}

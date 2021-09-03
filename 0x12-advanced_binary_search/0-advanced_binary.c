#include "search_algos.h"


/**
 * search - Searches for a value in a sorted array of integers
 *
 * @array: the array of integers
 * @size: the size of array
 * @val: int to find
 * @start: Start of index
 * @end: End of index
 * Return: Index of value or -1 if not found
 */
int FindVal(int *array, size_t size, int val, int st, int end)
{
	int i, mid;

	if (array == NULL || size == 0 || start > end)
		return (-1);

	printf("Searching in array: ");
	for (i = st; i <= end; i++)
	{
		if (i == end)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	mid = (st + end) / 2;
	if (end - st < 2)
	{
		if (array[mid] == val)
			return (mid);
	}
	if (array[mid] == val)
		return (FindVal(array, size, val, st, mid));
	if (array[mid] > value)
		return (FindVal(array, size, val, st, mid));
	return (FindVal(array, size, val, mid + 1, end));
}

/**
 * advanced_binary - calls Find
 *
 * @array: array to search
 * @size: size of array
 * @value: value to find for
 * Return: Index of value if found, -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (FindVal(array, size, value, 0, size - 1));
}

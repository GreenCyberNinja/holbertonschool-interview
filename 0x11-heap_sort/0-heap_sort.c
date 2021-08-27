#include "sort.h"

/**
 * downshift - shifts everything "down"
 *
 * @array: array to downshift
 * @nval: value of node to downshift
 * @root: starting point
 * @end: end point
 * @size: size of the array
 */
void downshift(int *array, int nval, int root, int end, size_t size)
{
	int left = 2 * root + 1;

	while (left <= end)
	{
		if (left < end)
		{
			if (array[left + 1] > array[left])
				left++;
		}
		if (nval >= array[left])
			break;
		array[root] = array[left];
		root = left;
		left = 2 * root + 1;
		array[root] = nval;
		print_array(array, size);
	}
}

/**
 * heap_sort - Sorts interger into an ascending array
 * @array: Pointer to array of int.
 * @size: Size of array.
 */
void heap_sort(int *array, size_t size)
{
	int i, lastN, lastNval;

	if (!array || size <= 1)
		return;

	for (i = size / 2; i >= 0; i--)
		downshift(array, array[i], i, size, size);

	for (lastN = size - 1; lastN > 0; lastN--)
	{
		lastNval = array[lastN];
		array[lastN] = array[0];
		array[0] = lastNval;
		print_array(array, size);
		downshift(array, lastNval, 0, lastN - 1, size);
	}
}
#include "sort.h"

/**
* merge_sort - sorts an array of integers via top-down merge algo
* @array: Array of integers to be sorted
* @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	RecursiveSort(array, size, tmp);
	free(tmp);
}

/**
* RecursiveSort - sorts array into temp array in ascending
* order via a merge sort recursive algorithm
* @ar: array to be sorted
* @size: size of array
* @tmp: array to hold sorted array
*/
void RecursiveSort(int *ar, size_t size, int *tmp)
{
	if (size > 1)
	{
		RecursiveSort(ar, size / 2, tmp);
		RecursiveSort(ar + size / 2, size - size / 2, tmp);
		PrintMerging(ar, size, size / 2, tmp);
	}
}

/**
* PrintMerging - merges two sorted arrays and prints output
* @ar: array to merge into
* @size: size of ar
* @mdl: middle index of arrays
* @tmp: temporary array to merge into ar
*/
void PrintMerging(int *ar, size_t size, size_t mdl, int *tmp)
{
    size_t i = 0, j = mdl, k = 0;

    printf("Merging...\n[left]: ");
    print_array(ar, mdl);
    printf("[right]: ");
    print_array(ar + mdl, size - mdl);
    while (k < size)
    {
        if (j == size)
        {
            tmp[k] = ar[i];
            i++;
        }
		else if (i == mdl || ar[j] < ar[i])
		{
			tmp[k] = ar[j];
			j++;
		}
		else
		{
			tmp[k] = ar[i];
			i++;
		}
		k++;
	}
	for (i = 0; i < size; i++)
		ar[i] = tmp[i];
	printf("[Done]: ");
	print_array(tmp, size);
}

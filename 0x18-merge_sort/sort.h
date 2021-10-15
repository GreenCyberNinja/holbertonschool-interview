#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void RecursiveSort(int *ar, size_t size, int *tmp);
void PrintMerging(int *ar, size_t size, size_t mdl, int *tmp);

#endif /* SORT_H */
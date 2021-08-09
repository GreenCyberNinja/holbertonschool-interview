#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: head of the skip list pointer
 * @value: value to search for
 * Return: pointer where value is located,
 * or NULL if value is not present in list.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *fast = list;
	skiplist_t *slow = list;

	if (list == NULL)
		return (NULL);
	fast = fast->express;
	while (fast && fast->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				fast->index, fast->n);
		slow = fast;
		fast = fast->express;
	}
	if (fast == NULL)
	{
		fast = slow->next;
		while (fast->next != NULL)
			fast = fast->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
				slow->index, fast->index);
	}
	else
	{
		printf("Value checked at index [%lu] = [%d]\n",
				fast->index, fast->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
				slow->index, fast->index);
	}
	while (slow && slow->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				slow->index, slow->n);
		slow = slow->next;
	}
	if (slow)
		printf("Value checked at index [%lu] = [%d]\n",
				slow->index, slow->n);
	return (slow);
}
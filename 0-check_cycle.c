#include "lists.h"
#include <stdio.h>


int check_cycle(listint_t *list)
{
	listint_t *head = list;
	
	while (head != NULL)
	{
		head = head->next;
		if (head == list)
			return (1);
	}
	return (0);
}

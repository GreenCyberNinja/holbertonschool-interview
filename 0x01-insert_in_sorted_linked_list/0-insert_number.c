#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* insert_node - inserts node into a sorted list
* @head: sorted list to insert into
* @number: int to be inserted
* Return: returns null or updated list
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *nav;
	listint_t *ans = malloc(sizeof(listint_t));

	if (ans == NULL)
		return (NULL);

	ans->n = number;
	nav = *head;

	while (nav->next != NULL)
	{
		if (nav->n <= number && nav->next->n >= number)
		{
			ans->next = nav->next;
			nav->next = ans;
			return (ans);
		}
		nav = nav->next;
	}
	ans->next = nav->next;
	nav->next = ans;
	return (ans);
}

#include "lists.h"

/**
 * find_listint_loop - finds loop in linked list if there
 * @head: pointer to head of list
 *  Return: pointer to node at start of loop or NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
    listint_t *trtl = head, *hare = head;

    while (trtl && hare && hare->next)
	{
		trtl = trtl->next;
		hare = hare->next->next;
		if (trtl == hare)
		{
			trtl = head;
			while (trtl != hare)
			{
				trtl = trtl->next;
				hare = hare->next;
			}
			return (trtl);
		}
	}
	return (NULL);
}
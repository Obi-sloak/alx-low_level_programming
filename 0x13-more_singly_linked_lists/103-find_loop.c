#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - Finds the loop contained in
 *                     a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If there is no loop - NULL.
 *         Otherwise - the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *T, *H;

	if (head == NULL || head->next == NULL)
		return (NULL);

	T = head->next;
	H = (head->next)->next;

	while (H)
	{
		if (T == H)
		{
			T = head;

			while (T != H)
			{
				T = T->next;
				H = H->next;
			}

			return (T);
		}

		T = T->next;
		H = (H->next)->next;
	}

	return (NULL);
}

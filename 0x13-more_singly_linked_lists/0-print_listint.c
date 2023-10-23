#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: A pointer to the head of the list_t list.
 *
 * Return: The scores of nodes in the list_t list.
 */
size_t print_listint(const listint_t *h)
{
	size_t scores = 0;

	while (h)
	{
		scores++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (scores);
}

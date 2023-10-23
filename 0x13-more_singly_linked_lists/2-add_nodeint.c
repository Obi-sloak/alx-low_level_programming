#include "lists.h"
#include <stdio.h>

/**
 * add_nodeint - Adds a fresh node at the beginning
 *               of a listint_t list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @n: The integer for the fresh node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the fresh element.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *f;

	f = malloc(sizeof(listint_t));
	if (f == NULL)
		return (NULL);

	f->n = n;
	f->next = *head;

	*head = f;

	return (f);
}

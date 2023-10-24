#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Insert a fresh node at a given positiion.
 * @head: First node address.
 * @idx: Position of the fresh node to be inserted in.
 * @n: Data of the fresh node.
 * Return: Address of the fresh node.
 **/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *fresh_node, *temp;
	unsigned int i = 0;

	if (*head == NULL && idx != 0)
		return (NULL);
	if (idx != 0)
	{
	temp = *head;
	for (; i < idx - 1 && temp != NULL; i++)
		temp = temp->next;
	if (temp == NULL)
		return (NULL);
	}
	fresh_node = malloc(sizeof(listint_t));
	if (fresh_node == NULL)
		return (NULL);
	fresh_node->n = n;
	if (idx == 0)
	{
		fresh_node->next = *head;
		*head = fresh_node;
		return (fresh_node);
	}
	fresh_node->next = temp->next;
	temp->next = fresh_node;
	return (fresh_node);
}

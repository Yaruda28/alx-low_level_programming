#include "lists.h"

/**
 * count_nodes - Returns the number of nodes in a linked list.
 *
 * @head: A pointer to the first node of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t count_nodes(const listint_t *head)
{
	size_t count = 0;

	while (head)
	{
		count++;
		head = head->next;
	}

	return (count);
}

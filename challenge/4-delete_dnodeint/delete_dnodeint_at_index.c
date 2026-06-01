#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index
 * of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	for (i = 0; i < index; i++)
	{
		if (*head == NULL)
			return (-1);
		*head = (*head)->next;
	}

	if (*head == NULL)
		return (-1);

	(*head)->prev->next = (*head)->next;

	if ((*head)->next != NULL)
		(*head)->next->prev = (*head)->prev;

	free(*head);
	return (1);
}

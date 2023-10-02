#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * node_swap - A function that swaps two nodes.
 * @head: A pointer to the head of the list.
 * @v1: A pointer to the first node to be swaped.
 * @v2: A pointer to the second node to be swaped.
 */
void node_swap(listint_t **head, listint_t **v1, listint_t *v2)
{
	(*v1)->next = v2->next;
	if (v2->next != NULL)
		v2->next->prev = *v1;
	v2->prev = (*v1)->prev;
	v2->next = *v1;
	if ((*v1)->prev != NULL)
		(*v1)->prev->next = v2;
	else
		*head = v2;
	(*v1)->prev = v2;
	*v1 = v2->prev;
}

/**
 * swap - A function that swaps two integers in an array.
 * @i: The first integer to swap.
 * @j: The second integer to swap.
 */
void swap(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * swap_ud - A function that swaps two nodes in a doubly-linked list.
 * @list: Pointer to the head of the list.
 * @i: First node to swap.
 * @j: Second node to swap.
 */
void swap_ud(listint_t **list, listint_t *i, listint_t *j)
{
	if (i->prev)
		i->prev->next = j;
	if (j->next)
		j->next->prev = i;
	i->next = j->next;
	j->prev = i->prev;
	i->prev = j;
	j->next = i;

	if (!i->prev)
		*list = i;
	if (!j->prev)
		*list = j;
}

#endif

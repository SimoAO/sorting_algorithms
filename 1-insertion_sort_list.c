#include "sort.h"
#include "functions.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *c, *p, *cn;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (c = (*list)->next; c != NULL; c = cn)
	{
		cn = c->next;
		p = c->prev;
		while (p != NULL && c->n < p->n)
		{
			node_swap(list, &p, c);
			print_list((const listint_t *)*list);
		}
	}
}

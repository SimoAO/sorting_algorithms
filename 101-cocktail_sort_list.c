#include "sort.h"
#include "functions.h"

/**
 * cocktail_sort_list - A function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int sw;
	listint_t *start = NULL, *end = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;

	while (1)
	{
		listint_t *current;
		sw = 0;
		for (current = start ? start : *list; current->next != end;
				current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_ud(list, current, current->next);
				print_list((const listint_t *)*list);
				sw = 1;
			}
		}
		end = current;

		if (!sw)
			break;

		sw = 0;
		for (current = end; current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_ud(list, current->prev, current);
				print_list((const listint_t *)*list);
				sw = 1;
			}
		}
		start = end->prev;

		if (!sw)
			break;
	}
}

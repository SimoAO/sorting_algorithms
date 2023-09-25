#include "sort.h"
#include "functions.h"

/**
 *  selection_sort - A function that sorts an array of integers
 *  in ascending order using the Selection sort algorithm.
 *  @array: array to sort
 *  @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, fm;

	if (array != NULL && size > 1)
	{
		for (i = 0; i < size; i++)
		{
			fm = i;
			for (j = i; j < size; j++)
			{
				if (array[j] < array[fm])
				{
					fm = j;
				}
			}
			if (array[i] != array[fm])
			{
				swap(&array[i], &array[fm]);
				print_array((const int *)array, size);
			}
		}
	}
}

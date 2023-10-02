#include "sort.h"
#include "functions.h"

/**
 * shell_sort - A function that sorts an array of integers in
 * ascending order using the Shell sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < (size / 3))
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			for (i = j; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				swap(array + j, array + (j - gap));
			}
		}
		print_array(array, size);
	}
}

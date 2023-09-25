#include "sort.h"
#include "functions.h"

/**
 * lomuto_partition - This function selects the pivot using Lomuto's partition scheme.
 *
 * @array: array to partition.
 * @low: low index of the array.
 * @high: high index of the array.
 * @size: size of the array.
 *
 * Return: The index of the pivot.
 */
int lomuto_partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * hybrid_quick_sort - A hybrid implementation of the Quick Sort algorithm.
 *
 * @array: array to sort.
 * @low: low index of the array.
 * @high: high index of the array.
 * @size: size of the array.
 */
void hybrid_quick_sort(int array[], int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		hybrid_quick_sort(array, low, pivot - 1, size);
		hybrid_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - A function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * @array: array to sort.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	hybrid_quick_sort(array, 0, size - 1, size);
}

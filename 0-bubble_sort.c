#include "sort.h"

/**
*bubble_sort - a function that sorts an array of integers in
*ascending order using the Bubble sort algorithm
*@array: array of numbers
*@size: size of the array
*/

void bubble_sort(int *array, size_t size)
{
	unsigned int s = 1, i;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (s != 0)
	{
		s = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				s = 1;
				print_array(array, size);
			}
		}
	}
}

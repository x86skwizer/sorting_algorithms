#include "sort.h"

/**
 * selection_sort - sorts using Selection sort algorithm
 * @array: array of integers
 * @size: array's size
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t sml;
	size_t i;
	size_t j;

	if (!array || size < 2)
		return;
	i = 0;
	while (i < size - 1)
	{
		sml = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[sml])
				sml = j;
		}
		if (sml != i)
		{
			tmp = array[i];
			array[i] = array[sml];
			array[sml] = tmp;
			print_array(array, size);
		}
		i++;
	}
}

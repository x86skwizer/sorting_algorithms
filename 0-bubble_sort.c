#include "sort.h"

/**
 * sorted_list - checks if array is sorted
 * @array: array
 * @size: size of array
 *
 * Return: 0 if true
 */
int sorted_list(int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array[i] && i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

/**
 * bubble_sort - sorts in ascending order using Bubble sort algo
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (!array)
		return;
	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			print_array(array, size);
		}
		i++;
		if (i == size - 1 && sorted_list(array, size))
			i = 0;
	}
}

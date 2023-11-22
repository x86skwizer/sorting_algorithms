#include "sort.h"

/**
 * swap - swap two int
 * @a: int
 * @b: int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - return pivot
 * @arr: array
 * @low: low index
 * @high: high index
 * @size: size of arr
 *
 * Return: pivot
 */
size_t partition(int array[], size_t size)
{
	int pivot;
	size_t i = -1;
	size_t j;

	if (!array || size < 2)
		return (0);

	pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_sort(array, size, 0);
			}
		}
	}
	if (i + 1 != size - 1)
	{
		swap(&array[i + 1], &array[size - 1]);
		print_sort(array, size, 0);
	}
	return (i + 1);
}

/**
 * sort - sorting array of int
 * @arr: array
 * @low: index
 * @high: index
 * @size: size of arr
 */
void sort(int *arr, int low, int high, int size)
{
	static int *p = (void *)0;
	static size_t s;

	if (!p && init)
	{
		p = array;
		s = size;
	}
	if (!init)
		print_array(p, s);
}

/**
 * quick_sort - sort the array
 * @array: array of int
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	print_sort(array, size, 1);
	pivot = partition(array, size);
	quick_sort(array, pivot);
	quick_sort(array + pivot, size - pivot);
}

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
int partition(int *arr, int low, int high, int size)
{
	int pivot;
	int i;
	int j;

	pivot = arr[high];
	i = (low - 1);
	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array(arr, (size_t)size);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	print_array(arr, (size_t)size);
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
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);
		sort(arr, low, pi - 1, size);
		sort(arr, pi + 1, high, size);
	}
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
	sort(array, 0, size - 1, size);
}

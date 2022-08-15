#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @bottom: lower element
 * @top: top element
 * @size: array's size
 * Return: i
 */
int partition(int *array, int bottom, int top, size_t size)
{
	int i = bottom - 1, j = bottom;
	int pivot = array[top], aux = 0;

	for (; j < top; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[top])
	{
		aux = array[i + 1];
		array[i + 1] = array[top];
		array[top] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_s - quick sort
 * @array: given array
 * @bottom: lower element
 * @top: top element
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int bottom, int top, size_t size)
{
	int pivot;

	if (bottom < top)
	{
		pivot = partition(array, bottom, top, size);
		quick_s(array, bottom, pivot - 1, size);
		quick_s(array, pivot + 1, top, size);
	}
}

#include "sort.h"
/**
 * swaping - swaps two pointers to integer
 *
 * @first: first pointer
 * @second: second pointer
 */
void swaping(int *first, int *second)
{
	int tempo;

	tempo = *first;
	*first = *second;
	*second = tempo;
}

/**
 * bubble_sort - sort an array of integer in ascending order
 * @array: the array to order and print
 * @size: size of array to order
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int j = 0, i = 0;

	if (size < 2)
		return;

	for (j = 0; j < (size - 1); j++)
		for (i = 1; i < size; i++)
			if (array[i - 1] > array[i])
			{
				swaping(&array[i - 1], &array[i]);
				print_array(array, size);
			}
}



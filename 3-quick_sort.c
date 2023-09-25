#include "sort.h"
/**
*swapping -  positions of two elements into an array
*@array: the array
*@itm1: the array of element
*@itm2: the array element
*/
void swapping(int *array, ssize_t itm1, ssize_t itm2)
{
	int temp;

	temp = array[itm1];
	array[itm1] = array[itm2];
	array[itm2] = temp;
}
/**
 *lo_partition - lo partition sorting scheme implementation
 *@array: array
 *@first: first element
 *@last: last element
 *@size: size of array
 *Return: return the position of the last element 
 */
int lo_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swapping(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swapping(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void quick_s(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lo_partition(array, first, last, size);

		quick_s(array, first, position - 1, size);
		quick_s(array, position + 1, last, size);
	}
}
/**
 *quick_sort - prepares for quicksort algorithm
 *@array: array
 *@size: size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	quick_s(array, 0, size - 1, size);
}

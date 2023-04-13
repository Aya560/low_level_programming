#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the minimum value to include in the array
 * @max: the maximum value to include in the array
 *
 * Return: pointer to the newly created array
 *         NULL if min > max or malloc fails
 */
int *array_range(int min, int max)
{
	int *arr, i, size;

	if (min > max)
	return (NULL);

	size = max - min + 1;

	arr = malloc(size * sizeof(int));
	if (arr == NULL)
	return (NULL);

	for (i = 0; i < size; i++, min++)
	arr[i] = min;

	return (arr);
}

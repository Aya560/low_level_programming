#include <stddef.h>

/*
 * array_iterator - Applies a function to each element of an array
 * @array: The array to iterate through
 * @size: The size of the array
 * @action: The function to apply to each element of the array
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (!array || !action)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}

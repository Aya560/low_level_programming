#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: number of elements in array
 * @size: size in bytes of each element
 *
 * Return: pointer to allocated memory, or NULL if nmemb or size is 0 or if
 * malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *arr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	return (NULL);

	arr = malloc(nmemb * size);
	if (arr == NULL)
	return (NULL);

	for (i = 0; i < nmemb * size; i++)
	arr[i] = 0;

	return ((void *)arr);
}

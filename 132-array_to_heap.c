#include "binary_trees.h"
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int x;
	heap_t *r = NULL;

	for (x = 0; x < size; x++)
		heap_insert(&r, array[x]);

	return (r);
}

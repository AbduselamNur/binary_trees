#include "binary_trees.h"
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int x;
	avl_t *r = NULL;

	for (x = 0; x < size; x++)
		avl_insert(&r, array[x]);

	return (r);
}

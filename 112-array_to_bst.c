#include "binary_trees.h"
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int x;
	bst_t *r = NULL;

	for (x = 0; x < size; x++)
		bst_insert(&r, array[x]);

	return (r);
}

#include "binary_trees.h"
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tr = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	tr = binary_tree_node(NULL, array[middle]);

	sata_helper(&tr, array, -1, middle);
	sata_helper(&tr, array, middle, size);

	return (tr);
}
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *ne = NULL;
	size_t middle;

	if (hi - lo > 1)
	{
		middle = (hi - lo) / 2 + lo;
		ne = binary_tree_node(*root, array[middle]);
		if (array[middle] > (*root)->n)
			(*root)->right = ne;
		else if (array[middle] < (*root)->n)
			(*root)->left = ne;
		sata_helper(&ne, array, lo, middle);
		sata_helper(&ne, array, middle, hi);
	}
}

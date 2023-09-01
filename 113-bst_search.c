#include "binary_trees.h"
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *nod = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (nod)
	{
		if (value == nod->n)
			return (nod);
		if (value < nod->n)
			nod = nod->left;
		else if (value > nod->n)
			nod = nod->right;
	}

	return (NULL);
}

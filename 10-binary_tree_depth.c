#include "binary_trees.h"
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dep = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		dep++;
		tree = tree->parent;
	}

	return (dep);
}

#include "binary_trees.h"
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d_first, d_second;

	if (!first || !second)
		return (NULL);

	d_first = binary_tree_depth(first);
	d_second = binary_tree_depth(second);

	while (d_first > d_second)
	{
		first = first->parent;
		d_first--;
	}
	while (d_second > d_first)
	{
		second = second->parent;
		d_second--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
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

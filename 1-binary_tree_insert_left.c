#include "binary_trees.h"
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *ne;

	if (!parent)
		return (NULL);

	ne = malloc(sizeof(binary_tree_t));
	if (!ne)
		return (NULL);

	ne->n = value;
	ne->parent = parent;
	ne->right = NULL;
	ne->left = parent->left;
	parent->left = ne;
	if (ne->left)
		ne->left->parent = ne;
	return (ne);
}

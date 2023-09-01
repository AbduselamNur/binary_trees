#include "binary_trees.h"
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *ne;

	if (!parent)
		return (NULL);

	ne = malloc(sizeof(binary_tree_t));
	if (!ne)
		return (NULL);

	ne->n = value;
	ne->parent = parent;
	ne->left = NULL;
	ne->right = parent->right;
	parent->right = ne;
	if (ne->right)
		ne->right->parent = ne;
	return (ne);
}

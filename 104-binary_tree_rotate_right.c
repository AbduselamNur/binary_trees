#include "binary_trees.h"
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *t = NULL, *parent;

	if (!tree || !tree->left)
		return (NULL);
	t = tree;
	parent = tree->parent;
	tree = tree->left;
	tree->parent = NULL;
	if (tree->right)
	{
		t->left = tree->right;
		tree->right->parent = t;
	}
	else
		t->left = NULL;
	t->parent = tree;
	tree->right = tmp;
	if (parent)
		parent->left = tree;
	tree->parent = parent;
	return (tree);
}

#include "binary_trees.h"
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *t = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);
	t = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		t->right = tree->left;
		tree->left->parent = t;
	}
	else
		t->right = NULL;
	t->parent = tree;
	tree->left = t;
	if (parent)
		parent->right = tree;
	tree->parent = parent;
	return (tree);
}

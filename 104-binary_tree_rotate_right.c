#include "binary_trees.h"
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tm = NULL, *parent;

	if (!tree || !tree->left)
			return (NULL);
	tm = tree;
	parent = tree->parent;
	tree = tree->left;
	tree->parent = NULL;
	if (tree->right)
		{
				tm->left = tree->right;
					tree->right->parent = tm;
					}
	else
			tm->left = NULL;
	tm->parent = tree;
	tree->right = tm;
	if (parent)
			parent->left = tree;
	tree->parent = parent;
	return (tree);
}	

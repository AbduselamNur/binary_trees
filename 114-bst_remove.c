#include "binary_trees.h"
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tm = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tm = root->right;
			free(root);
			return (tm);
		}
		else if (!root->right)
		{
			tm = root->left;
			free(root);
			return (tm);
		}
		tm = bst_min_val(root->right);
		root->n = tm->n;
		root->right = bst_remove(root->right, tm->n);
	}
	return (root);
}
bst_t *bst_min_val(bst_t *root)
{
	bst_t *mi = root;

	while (mi->left)
		mi = mi->left;

	return (mi);
}

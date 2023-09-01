#include "binary_trees.h"
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tm = NULL;
	bst_t *se = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	tm = *tree;
	while (tm)
	{
		se = tm;
		if (value < tm->n)
			tm = tm->left;
		else if (value > tm->n)
			tm = tm->right;
		else if (value == tm->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (se == NULL)
		se = new;
	else if (value < se->n)
	{
		se->left = new;
		new->parent = se;
	}
	else
	{
		se->right = new;
		new->parent = se;
	}

	return (new);
}

#include "binary_trees.h"
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tm = *tree;
	bst_t *second = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = new;

	while (tm)
	{
		second = tm;
		if (value < tm->n)
			tm = tm->left;
		else if (value > tm->n)
			tm = tm->right;
		else if (value == tm->n)
			return (NULL);
	}

	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}

	return (new);
}
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = 0;
	avl_t *nod = bst_insert(tree, value);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < nod->left->n)
		return (binary_tree_rotate_right(nod));
	if (balance < -1 && value > nod->right->n)
		return (binary_tree_rotate_left(nod));
	if (balance > 1 && value > nod->left->n)
	{
		nod->left = binary_tree_rotate_left(nod->left);
		return (binary_tree_rotate_right(nod));
	}
	if (balance < -1 && value < nod->right->n)
	{
		nod->right = binary_tree_rotate_right(nod->right);
		return (binary_tree_rotate_left(nod));
	}

	return (nod);
}

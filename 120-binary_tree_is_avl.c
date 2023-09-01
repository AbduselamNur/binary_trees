#include "binary_trees.h"
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int p_l, p_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	p_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	p_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(p_l - p_r) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
}
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_l = 0;
	size_t h_r = 0;

	if (!tree)
		return (0);

	h_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (h_l > h_r ? h_l : h_r);
}

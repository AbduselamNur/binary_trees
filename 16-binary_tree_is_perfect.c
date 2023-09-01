#include "binary_trees.h"
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t hei = 0;
	size_t nod = 0;
	size_t pow = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	hei = binary_tree_height(tree);
	nod = binary_tree_size(tree);

	pow = (size_t)_pow_recursion(2, height + 1);
	return (pow - 1 == nod);
}

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));

}
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
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

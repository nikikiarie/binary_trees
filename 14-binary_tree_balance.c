#include "binary_trees.h"

/**
 * binary_tree_heightt - looks for balancedtree
 * @tree: tree
 * Return: height
 */

size_t binary_tree_heightt(const binary_tree_t *tree)
{
	size_t r = 0, l = 0;

	if (!tree)
		return (0);
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_heightt(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_heightt(tree->right) : 1;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int l = 0, r = 0, total = 0;

	if (!tree)
		return (0);
	l = ((int)binary_tree_heightt(tree->left));
	r = ((int)binary_tree_heightt(tree->right));
	total = l - r;

	return (total);
}

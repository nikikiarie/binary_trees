#include "binary_trees.h"

/**
 * binary_tree_levelorder - Level-order traversal of a binary tree
 * @tree: Pointer to the root of the tree
 * @func: Function to apply to each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t current_level, total_levels;

	if (!tree || !func)
		return;

	total_levels = get_tree_height(tree) + 1;

	for (current_level = 1; current_level <= total_levels; current_level++)
		level_helper(tree, func, current_level);
}

/**
 * level_helper - Helper to apply function at each level
 * @tree: Pointer to the current node
 * @func: Function to apply to node's value
 * @level: Current level to apply the function on
 */
void level_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else
	{
		level_helper(tree->left, func, level - 1);
		level_helper(tree->right, func, level - 1);
	}
}

/**
 * get_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t get_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	left_height = tree->left ? 1 + get_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + get_tree_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

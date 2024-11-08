#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if complete, 0 if not, or 0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t tree_size;

	if (!tree)
		return (0);
	tree_size = binary_tree_size(tree);

	return (c_done(tree, 0, tree_size));
}

/**
 * c_done - Recursively checks if a binary tree is complete
 * @tree: Pointer to the node to check
 * @node_index: Index of the current node
 * @total_nodes: Total nodes in the tree
 *
 * Return: 1 if complete, 0 if not
 */
int c_done(const binary_tree_t *tree, size_t node_index, size_t total_nodes)
{
	if (!tree)
		return (1);

	if (node_index >= total_nodes)
		return (0);

	return (c_done(tree->left, 2 * node_index + 1, total_nodes) &&
		c_done(tree->right, 2 * node_index + 2, total_nodes));
}

/**
 * binary_tree_size - Calculates the size of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: The size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

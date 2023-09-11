#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the depth.
 *
 * Return: the depth of the given node in the binary tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	depth = binary_tree_depth(tree->parent);

	if (tree->parent == NULL)
		return (0);
	else
		return (depth + 1);
}

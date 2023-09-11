#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 *
 * @parent: pointer to the parent node.
 * @value: integer stored in the node.
 *
 * Return: a pointer to the new created binary tree node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_tree = NULL;

	new_tree = malloc(sizeof(binary_tree_t));

	if (new_tree == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	new_tree->n = value;
	new_tree->parent = parent;
	new_tree->left = NULL;
	new_tree->right = NULL;

	return (new_tree);
}

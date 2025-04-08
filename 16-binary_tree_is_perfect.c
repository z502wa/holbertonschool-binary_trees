#include "binary_trees.h"

/**
 * depth_of_leftmost_leaf - Returns depth of the leftmost leaf
 * @tree: Pointer to the root node
 *
 * Return: Depth in levels
 */
size_t depth_of_leftmost_leaf(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect_recursive - Recursively checks if tree is perfect
 * @tree: Pointer to current node
 * @depth: Expected depth of all leaves
 * @level: Current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (
		is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1)
	);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if perfect, 0 if not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = depth_of_leftmost_leaf(tree);
	return (is_perfect_recursive(tree, depth, 0));
}

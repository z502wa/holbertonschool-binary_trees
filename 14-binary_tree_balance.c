#include "binary_trees.h"

/**
 * height - A helper function to calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree (number of levels)
 */
static size_t height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * binary_tree_balance - Calculates the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The balance factor (left subtree height - right subtree height)
 *         or 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = (int)height(tree->left);
	right_height = (int)height(tree->right);

	return (left_height - right_height);
}

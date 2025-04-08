#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if full, 0 if not or if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* إذا كانت العقدة لا تملك أبناء */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* إذا كانت العقدة تملك كلا الابنين */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* إذا كانت تملك ابن واحد فقط */
	return (0);
}

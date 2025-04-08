#include "binary_trees.h"

/**
 * height - A helper function to calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree (number of levels)
 */
static size_t height(const binary_tree_t *tree)
{
    /* If the tree is NULL, its height is 0 */
    if (tree == NULL)
        return (0);

    /* Calculate the height of the left and right subtrees */
    size_t left_h = height(tree->left);
    size_t right_h = height(tree->right);

    /* Return the larger height among the two subtrees plus 1 for the current node */
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
    /* If the tree is NULL, the balance factor is 0 */
    if (tree == NULL)
        return (0);

    /* The balance factor = height(left subtree) - height(right subtree) */
    return ((int)height(tree->left) - (int)height(tree->right));
}

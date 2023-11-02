#include "binary_trees.h"


/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *right_child, *temp_right;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	right_child = tree->left;
	temp_right = right_child->right;
	right_child->right = tree;
	tree->left = temp_right;
	if (temp_right != NULL)
		temp_right->parent = tree;
	temp_right = tree->parent;
	tree->parent = right_child;
	right_child->parent = temp_right;
	if (temp_right != NULL)
	{
		if (temp_right->left == tree)
			temp_right->left = right_child;
		else
			temp_right->right = right_child;
	}

	return (right_child);
}


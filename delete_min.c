#include "rbt.h"

int delete_minimum(tree_t **root)
{
	tree_t *current;

	if (root == NULL || *root == NULL)
		return FAILURE;

	current = *root;
	
	while (current->left != NULL)
		current = current->left;

	return delete(root, current->data);
}

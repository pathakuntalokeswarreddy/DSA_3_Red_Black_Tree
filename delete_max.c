#include "rbt.h"

int delete_maximum(tree_t **root)
{
	tree_t *current;

	if (root == NULL || *root == NULL)
		return FAILURE;

	current = *root;
	
	while (current->right != NULL)
		current = current->right;

	return delete(root, current->data);
}

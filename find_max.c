#include "rbt.h"

int find_maximum(tree_t **root, data_t *max)
{
	tree_t *current;

	if(root == NULL || *root==NULL || max==NULL)
		return FAILURE;

	current = *root;
	
	while(current->right != NULL)
		current = current->right;

	*max=current->data;

	return SUCCESS;
}

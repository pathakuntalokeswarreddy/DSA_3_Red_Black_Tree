#include "rbt.h"

int find_minimum(tree_t **root, data_t *min)
{
	tree_t *current;
	
	if(root ==  NULL || *root==NULL || min == NULL)
		return FAILURE;
    
	current=*root;

	while(current->left != NULL)
		current=current->left;

	*min=current->data;

	 return SUCCESS;
}

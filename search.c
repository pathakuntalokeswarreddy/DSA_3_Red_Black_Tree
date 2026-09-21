#include "rbt.h"
#include<stdio.h>

int search(tree_t *root, data_t item)
{
    printf("in search\n");
    while(root!=NULL)
    {
        if(item == root->data)
            return SUCCESS;
        else if(item < root->data)
            root=root->left;
        else
            root=root->right;
    }
    return FAILURE;
}
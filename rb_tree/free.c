#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "head.h"

void free_tree(node* root)
{
    if (root == NULL) return 0;

    free_tree(root->left);
    free_tree(root->right);

    free(root);
}

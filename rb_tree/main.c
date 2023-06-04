#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "head.h"

int main()
{
    setlocale(LC_CTYPE, "Russian");

    node* root = (node *) malloc(sizeof(node));             // выделяем память под корень
    if (!root) return NULL;

    root->data = 64;                                        // пример дерева
    root->color = BLACK;

    root->left = (node*) malloc(sizeof(node));              // выделяем память под левый узел
    if (!root->left) return NULL;

    root->left->data = 15;
    root->left->color = RED;

    root->left->left = NULL;
    root->left->right = NULL;

    root->right = (node *) malloc(sizeof(node));            // выделяем память под правый узел
    if (!root->right) return NULL;

    root->right->data = 79;
    root->right->color = RED;

    root->right->left = NULL;
    root->right->right = NULL;

    if (is_rb_tree(root)) printf("это красно-чёрное дерево\n");
    else printf("это не красно-чёрное дерево\n");

    free_tree(root);

    return 0;
}

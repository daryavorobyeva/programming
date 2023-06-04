#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "head.h"

int check_rb_tree(node* root, int* black_count)
{
    if (root == NULL)      // если дерево пустое, возвращаем черный цвет
    {
        *black_count = 1;
        return BLACK;
    }

    if (root->left != NULL && root->left->data > root->data)
        return RED;      // все элементы в левом поддереве меньше корня? нет, если левый ребёнок больше "корня", то не BST

    if (root->right != NULL && root->right->data < root->data)
        return RED;      // все элементы в правом поддереве больше корня? нет, если правый ребёнок меньше "корня", то не BST

    int left_black_count, right_black_count;      // для хранения кол-ва черных в левом и правом поддеревьях

    int left_color = check_rb_tree(root->left, &left_black_count);      // рекурсивно проверяем левое и правое поддеревья
    int right_color = check_rb_tree(root->right, &right_black_count);


    if (left_color == RED || right_color == RED) return RED;      // если хотя бы один из потомков красный, то не кчд
    if (left_black_count != right_black_count) return RED;      // если кол-во черных левом и правом поддеревьях не кчд

    if (root->color == BLACK) *black_count = left_black_count + 1;      // обновляем количество черных в текущем узле
    else *black_count = left_black_count;

    return BLACK;      // возвращаем цвет текущего узла
}

int is_rb_tree(node* root)
{
    if (root == NULL) return 1;                             // пустое => кчд
    if (root->color != BLACK) return 0;                     // корень не черный => не кчд

    int black_count;                                        // для хранения кол-ва черных узлов

    return check_rb_tree(root, &black_count) == BLACK;
}


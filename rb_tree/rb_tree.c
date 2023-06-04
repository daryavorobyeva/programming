#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "head.h"

int check_rb_tree(node* root, int* black_count)
{
    if (root == NULL)      // ���� ������ ������, ���������� ������ ����
    {
        *black_count = 1;
        return BLACK;
    }

    if (root->left != NULL && root->left->data > root->data)
        return RED;      // ��� �������� � ����� ��������� ������ �����? ���, ���� ����� ������ ������ "�����", �� �� BST

    if (root->right != NULL && root->right->data < root->data)
        return RED;      // ��� �������� � ������ ��������� ������ �����? ���, ���� ������ ������ ������ "�����", �� �� BST

    int left_black_count, right_black_count;      // ��� �������� ���-�� ������ � ����� � ������ �����������

    int left_color = check_rb_tree(root->left, &left_black_count);      // ���������� ��������� ����� � ������ ����������
    int right_color = check_rb_tree(root->right, &right_black_count);


    if (left_color == RED || right_color == RED) return RED;      // ���� ���� �� ���� �� �������� �������, �� �� ���
    if (left_black_count != right_black_count) return RED;      // ���� ���-�� ������ ����� � ������ ����������� �� ���

    if (root->color == BLACK) *black_count = left_black_count + 1;      // ��������� ���������� ������ � ������� ����
    else *black_count = left_black_count;

    return BLACK;      // ���������� ���� �������� ����
}

int is_rb_tree(node* root)
{
    if (root == NULL) return 1;                             // ������ => ���
    if (root->color != BLACK) return 0;                     // ������ �� ������ => �� ���

    int black_count;                                        // ��� �������� ���-�� ������ �����

    return check_rb_tree(root, &black_count) == BLACK;
}


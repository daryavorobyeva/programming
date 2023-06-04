#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef enum {RED, BLACK} rb_color;

typedef struct node
{
    int data;                                     // ��������
    rb_color color;                               // ����
    struct node* left;                            // ��������� �� ����� � ������ ����
    struct node* right;
}node ;

int check_rb_tree(node* root, int* black_count);  /* ���������� ��������� ������ ���� ������ �� �������� ���.
                                                   * ���� ���� �� �������� ��, �� ������� ���������� �������� RED = 0.
                                                   * ���� ���� �������� �������, �� ������� ���������� �������� RED = 0.
                                                   * ���� ���-�� ������ ����� � ����� � ������ ����������� �� ���������,
                                                   * �� ������� ���������� �������� RED = 0.
                                                   * � ��������� ������, ������� ��������� ���������� ������ ����� � ������� ����
                                                   * � ���������� �������� BLACK = 1.
                                                   */

int is_rb_tree(node* root);                       /* �������� ������� check_rb_tree � �������� �� ��������� �� ������
                                                   * � ��������� �� ���������� black_count.
                                                   * ���� ������� check_rb_tree ���������� BLACK,
                                                   * �� ������� is_rb_tree ���������� 1, ����� - 0.
                                                   */
void free_tree(node* root);                       // ����������� ������� ������ ��� ����� ������

#endif // HEAD_H_INCLUDED

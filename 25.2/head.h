#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef double element_t;

typedef struct node              // ���� �������, "������" � ��������� ������
{
    struct node *next;
    struct node *prev;
    element_t data;
} node;

typedef struct deque             // �������, ������ ��������� �� ���� - "������" � "�����"
{
    node *head;
    node *tail;
} deque;

deque* deque_alloc();                                  // �������� ������ ��� ��������� �������; ���������� ��������� ��
                                                       // ��������� ���������, ���� ��������� �������, ����� NULL.

void deque_free (deque *d);                            // ����������� ������, ���������� ��� ������� � �� ���������;
                                                       // ������� ��������, ��������� deque_pop_back(), ���� ������� �� ������ ������;
                                                       // ����� ������������� ������.

int deque_push_front (deque *d, element_t e);          // ��������� ������� � ������ �������; �������� ������ ��� ������ ��������;
                                                       // ������� ���������� 0, ���� �������, ����� -1.

int deque_push_back (deque *d, element_t e);           // ����������, �� ���������� � ����� �������.

element_t deque_pop_front (deque *d);                  // ������� ������� �� ������ �������; ��������� �������� ������� ��������,
                                                       // �������  � ����������� ������; ���� ������� �����, ���������� -1.

element_t deque_pop_back (deque *d);                   // ����������, �� �������� �� �����.

deque* deque_clone (const deque *d);                   // ������� ����� �������; �������� ������ ��� ����� �������
                                                       // � �������� ��� �������� �� ������ ������� � �����;
                                                       // ���������� ��������� �� ����� �������, ����� NULL.

void print_deque(deque *d);                            // ������� �������� ��������� �������; �������� � ������ � ���������
                                                       // � ���������� ��������, ���� �� ��������� �����.

element_t deque_get_front(deque *d);                   // ���������� �������� ������� �������� �������.

#endif // HEAD_H_INCLUDED

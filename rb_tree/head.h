#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef enum {RED, BLACK} rb_color;

typedef struct node
{
    int data;                                     // значение
    rb_color color;                               // цвет
    struct node* left;                            // указатели на левый и правый узлы
    struct node* right;
}node ;

int check_rb_tree(node* root, int* black_count);  /* Рекурсивно проверяет каждый узел дерева на свойства кчд.
                                                   * Если узел не является кч, то функция возвращает значение RED = 0.
                                                   * Если узел является красным, то функция возвращает значение RED = 0.
                                                   * Если кол-во черных узлов в левом и правом поддеревьях не совпадает,
                                                   * то функция возвращает значение RED = 0.
                                                   * В противном случае, функция обновляет количество черных узлов в текущем узле
                                                   * и возвращает значение BLACK = 1.
                                                   */

int is_rb_tree(node* root);                       /* Вызывает функцию check_rb_tree и передает ей указатель на корень
                                                   * и указатель на переменную black_count.
                                                   * Если функция check_rb_tree возвращает BLACK,
                                                   * то функция is_rb_tree возвращает 1, иначе - 0.
                                                   */
void free_tree(node* root);                       // рекурсивная очистка памяти для всего дерева

#endif // HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "head.h"

int main()
{
    setlocale(LC_CTYPE, "Russian");

    size_t n;
    printf("введите число элементов очереди\n");
    scanf("%i", &n);

    deque *deque = deque_alloc();

    printf("введите элементы очереди по порядку\n");

    for (int i = 0; i < n ; ++i)
    {
        double a;
        scanf("%lf", &a);
        deque_push_back (deque, a);
    }

    printf("\n");

    printf("печать очереди:\n");
    print_deque(deque);

    printf("удалили элемент из начала:\n");
    deque_pop_front(deque);
    print_deque(deque);

    printf("удалили элемент из конца:\n");
    deque_pop_back(deque);
    print_deque(deque);

    printf("первый элемент:\n");
    printf("%.2lf", deque_get_front(deque));

    deque_free (deque);

    return 0;
}

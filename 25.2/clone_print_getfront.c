#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "head.h"

deque* deque_clone (const deque *d)
{
    deque *r = deque_alloc();
    node *t = d->head;

    if (!r) return NULL;

    while (t != NULL)
    {
        if (deque_push_back(r, t->data)) return NULL;
        t = t->next;
    }
    return r;
}

void print_deque(deque *d)
{
    node *current = d->head;

    while(current != NULL)
    {
        printf("%.2lf ", current->data);
        current = current->next;
    }

    printf("\n");
}

element_t deque_get_front(deque *d)
{
    if (d->head != NULL) return d->head->data;

    return 0;
}

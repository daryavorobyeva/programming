#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "head.h"

deque* deque_alloc()
{
    deque *d =(deque *) malloc(sizeof(deque));
    if (!d) return NULL;

    d->head = NULL;
    d->tail = NULL;

    return d;
}

void deque_free (deque *d)
{
    while (!deque_pop_back(d));

    free(d);
}

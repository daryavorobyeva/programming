#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "head.h"

int deque_push_front (deque *d, element_t e)
{
    node *n = (node *) malloc (sizeof (node));

    if (!n) return - 1;

    n->data = e;
    n->next = d->head;
    n->prev = NULL;

    if (d->tail == NULL) d->head = d->tail = n;
    else
    {
        d->head->prev = n;
        d->head = n;
    }

    return 0;
}

int deque_push_back (deque *d, element_t e)
{
    node *n = (node *)  malloc (sizeof (node));

    if (!n) return -1;

    n->data = e;
    n->prev = d->tail;
    n->next = NULL;

    if (d->head == NULL) d->head = d->tail = n;
    else
    {
        d->tail->next = n;
        d->tail = n;
    }

    return 0;
}

element_t deque_pop_front (deque *d)
{
    if (d->head)
    {
        element_t e = d->head->data;
        node *n = d->head;

        if (d->head == d->tail) d->head = d->tail = NULL;

        else n->next->prev = NULL;
        d->head = n->next;

        free(n);

        return e;
    }
    return -1;
}

element_t deque_pop_back (deque *d)
{
    if (d->head)
    {
        element_t e = d->tail->data;
        node *n = d->tail;

        if (d->head == d->tail) d->head = d->tail = NULL;
        else n->prev->next = NULL;
        d->tail = n->prev;

        free(n);

        return e;
    }
    return -1;
}

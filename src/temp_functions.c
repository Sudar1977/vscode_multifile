#include <stdio.h>
#include "temp_functions.h"
#include <stdlib.h>

void push(stack **p, datatype data)
{
    stack *ptmp;
    ptmp = malloc(sizeof(stack));
    ptmp->value = data;
    ptmp->next = *p;
    *p = ptmp;
}

_Bool empty_stack(stack *p)
{
    return p == NULL;
}

datatype pop(stack **p)
{
    stack *ptmp = *p;
    datatype c;
    if (empty_stack(*p))
        exit(1); // Попытка взять из пустого стека
    c = ptmp->value;
    *p = ptmp->next;
    free(ptmp);
    return c;
}

void init_stack_arr(stack_arr *st)
{
    st->size = 4;
    st->sp = 0;
    st->item = malloc(4 * sizeof(datatype));
}
void delete_stack_arr(stack_arr *st)
{
    free(st->item);
}

int empty_stack_arr(stack_arr *st)
{
    return (st->sp < 1);
}

void push_arr(stack_arr *st, datatype value)
{
    if (st->sp == st->size - 1)
    {
        st->size = st->size * 2;
        st->item = realloc(st->item, st->size * sizeof(datatype));
    }
    st->item[st->sp++] = value;
}

void pop_arr(stack_arr *st, datatype *value)
{
    if (st->sp < 1)
    {
        printf("stack empty");
        exit(1);
    }
    *value = st->item[--(st->sp)];
}

_Bool empty_queue(queue *p)
{
    return p == NULL;
}

void enqueue(queue **pl, datatype data)
{
    queue *ptmp = *pl;
    queue *elem = malloc(sizeof(queue));
    elem->value = data;
    elem->next = NULL;
    if (*pl == NULL)
    {
        *pl = elem;
        return;
    }
    while (ptmp->next)
        ptmp = ptmp->next;
    ptmp->next = elem;
}

datatype dequeue(queue **p)
{
    queue *ptmp = *p;
    datatype c;
    if (empty_queue(*p))
    { // Попытка взять из пустой очереди
        fprintf(stderr, "Error. Queue is empty\n");
        exit(1);
    }
    c = ptmp->value;
    *p = ptmp->next;
    free(ptmp);
    return c;
}

void enqueue_recurs(queue **pl, datatype data)
{
    if (*pl == NULL)
    {
        (*pl) = malloc(sizeof(queue));
        (*pl)->value = data;
        (*pl)->next = NULL;
        return;
    }
    else
    {
        enqueue_recurs(&((*pl)->next), data);
    }
}

void print_list(queue *pl)
{
    for (;pl;pl = pl->next)
    {
        printf("%d ", pl->value);
    }
    printf("\n");
}

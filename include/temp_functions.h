#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

// #include <stdint.h>
// #include "main.h"

typedef int datatype;

typedef struct list 
{
    datatype value;
    struct list *next;
} stack;

typedef struct {
  datatype *item;
  int size;
  int sp;
} stack_arr;

typedef struct listq {
    datatype value;
    struct listq * next;
}queue;


void push(stack **p,datatype data);
_Bool empty_stack(stack *p);
datatype pop(stack **p);

void init_stack_arr(stack_arr *st);
void delete_stack_arr(stack_arr *st);
int empty_stack_arr(stack_arr *st);
void push_arr(stack_arr *st, datatype value);
void pop_arr (stack_arr *st, datatype *value);

void enqueue(queue **pl, datatype data);
datatype dequeue(queue **p);


#endif
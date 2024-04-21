#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../include/main.h"
#include "../include/temp_functions.h"
#include <stdlib.h>

int main(void)
{
    // stack *p = NULL; // Важно для корректной работы присвоить NULL
    // for (size_t i = 0; i <= 5; i++)
    // {
    //     /* code */
    //     push(&p,i);
    // }
    // for (size_t i = 0; i <= 5; i++)
    // {
    //     /* code */
    //     printf("%d\n",pop(&p));
    // }

    // stack_arr st;
    // int a, i;
    // init_stack_arr(&st);
    // do
    // {
    //     scanf("%d", &a);
    //     push_arr(&st, a);
    // } while (a != 0);
    // for (i = 0; i < st.sp; i++)
    //     printf("%d ", st.item[i]);
    // while (!empty_stack_arr(&st))
    // {
    //     pop_arr(&st, &a);
    //     printf("%d ", a);
    // }
    // free(st.item);

    queue *pq = NULL;

    for (int i = 1; i <= 5; i++)
        enqueue(&pq, i);
    for (int i = 1; i <= 5; i++)
        printf("%d\n", dequeue(&pq));

    return 0;
}
#include "push_swap.h"
#include <stdio.h>

int main(int av, char **args)
{
    t_stack *a;
    t_stack *temp;

    fill_stack(args, &a, av, 0);
    while (a)
    {
        temp = a;
        a = a->next;
        printf("%d\n", temp->value);
        free(temp);
    }
}
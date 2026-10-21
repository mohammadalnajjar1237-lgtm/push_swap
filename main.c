#include "push_swap.h"
#include <stdio.h>

int main(int av, char **args)
{
    t_stack *a;

    fill_stack(args, &a, av, 0);
    while (a)
    {
        printf("%d\n", a->value);
        a = a->next;
    }
    free(a);
}
#include "push_swap.h"
#include <stdio.h>

int main(int av, char **args)
{
    t_stack *a = NULL;
    t_stack *temp;
    fill_stack(args, &a, av, 0);
    reverse_rotate_a(&a);
    while (a)
    {
        temp = a;
        a = a->next;
        printf("%d\n", temp->value);
        free(temp);
    }
    /*while (temp2)
    {
        temp = temp2;
        temp2 = temp2->next;
        printf("%d\n", temp->value);
        free(temp);
    }*/
}
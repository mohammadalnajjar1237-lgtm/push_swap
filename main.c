#include "push_swap.h"
#include <stdio.h>

int main(int av, char **args)
{
    t_stack *a = NULL;
    t_stack *temp;
    t_stack *b;
    int size = fill_stack(args, &a, av, 0);
    sort_simple(&a, b, size, 1);
    //int d = compute_disorder(a, size) * 10000;
    //ft_printf("%f\n", d);
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
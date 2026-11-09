#include "push_swap.h"

int main(int av, char **args)
{
    t_stack *a = NULL;
    if (av == 1)
    {
        ft_printf("./push_swap");
        return (1);
    }
    push_swap(args, av, &a);
    free_nodes(a);
    /*t_stack *temp;
    while (a)
    {
        temp = a;
        a = a->next;
        ft_printf("%d\n", temp->value);
    }*/
}
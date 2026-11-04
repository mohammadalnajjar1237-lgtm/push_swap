#include "push_swap.h"
#include <stdio.h>

int main(int av, char **args)
{
    t_stack *a = NULL;
    t_stack *temp;
    
    push_swap(args, av);









   while (a)
    {
        temp = a;
        a = a->next;
        printf("%d\n", temp->value);
        free(temp);
    }
}
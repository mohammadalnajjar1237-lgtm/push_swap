#include "push_swap.h"
#include <stdio.h>
static void free_nodes(t_stack *a)
{  
    t_stack *temp;

    while (a)
    {
        temp = a;
        a = a->next;
        free(temp);
    }
}
int main(int av, char **args)
{
    t_stack *a = NULL;
    
    push_swap(args, av, &a);
    free_nodes(a);
  /* while (a)
    {
        temp = a;
        a = a->next;
        printf("%d\n", temp->value);
        free(temp);
    }*/

}
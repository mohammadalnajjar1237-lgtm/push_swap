#include "push_swap.h"

int is_empty_or_unary(t_stack *a)
{
    if (a == NULL || a -> next == NULL)
        return (1);
    return (0);
}

int swap_b(t_stack **b, int *ops_count)
{
    t_stack *temp_head;

    if (NULL || is_empty_or_unary(*b))
        return (0);
    temp_head = (*b) -> next;
    (*b) -> next = ((*b) -> next) -> next;
    temp_head -> next = *b;
    *b  = temp_head;
    //ft_printf("sb\n");
    if (ops_count)
    {
        write(1, "sb\n", 3);
        ops_count[1] += 1;
    }
    return (1);
}

int swap_a(t_stack **a, int *ops_count)
{
    t_stack *temp_head;

    if (a == NULL || is_empty_or_unary(*a))
        return (0);
    temp_head = (*a) -> next;
    (*a) -> next = ((*a) -> next) -> next;
    temp_head -> next = *a;
    *a  = temp_head;
    //ft_printf("sa\n");
    if (ops_count)
    {
        write(1, "sa\n", 3);
        ops_count[0] += 1;
    }
    return (1);
}

int ss(t_stack **a, t_stack **b,int *ops_count)
{
    if (!swap_a(a, NULL) || !swap_b(b, NULL))
        return (0);
    write(1, "ss\n", 3);
    //ft_printf("ss\n");
    if (ops_count)
        ops_count[2] += 1;
    return (1);
}

int push_a(t_stack **a, t_stack **b, int *ops_count)
{
    t_stack *temp;

    if (*b == NULL || b == NULL)
        return (0);
    temp = (*b) ->next;
    ft_lstadd_front2(a, *b, NULL);
    *b = temp;
    write(1, "pa\n", 3);
   // ft_printf("pa\n");
     if (ops_count)
        ops_count[3] += 1;
    return (1);
}

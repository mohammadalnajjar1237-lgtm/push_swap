#include "push_swap.h"

int is_empty_or_unary(t_stack *a)
{
    if (a == NULL || a -> next == NULL)
        return (1);
    return (0);
}

int swap_b(t_stack **b)
{
   t_stack *temp;
    t_stack *temp_head;

    if (is_empty_or_unary(*b))
        return (0);
    temp = ((*b)->next) -> next;
    ((*b)->next)->next = *b;
    temp_head = (*b) -> next;
    (*b)->next = temp;
    *b = temp_head;
    //ft_printf("sa\n");
    return (1);
}

int swap_a(t_stack **a)
{
    t_stack *temp;
    t_stack *temp_head;

    if (is_empty_or_unary(*a))
        return (0);
    temp = ((*a)->next) -> next;
    ((*a)->next)->next = *a;
    temp_head = (*a) -> next;
    (*a)->next = temp;
    *a = temp_head;
    //ft_printf("sa\n");
    return (1);
}

int ss(t_stack *a, t_stack *b)
{
    if (!swap_a(&a) || !swap_b(&b))
        return (0);
    //ft_printf("ss\n");
    return (1);
}

int push_a(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*b == NULL)
        return (0);
    temp = (*b) ->next;
    ft_lstadd_front2(a, *b);
    *b = temp;
    return (1);
}

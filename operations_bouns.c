#include "push_swap.h"

int swap_b_bouns(t_stack **b)
{
    t_stack *temp_head;

    if (NULL || is_empty_or_unary(*b))
        return (0);
    temp_head = (*b) -> next;
    (*b) -> next = ((*b) -> next) -> next;
    temp_head -> next = *b;
    *b  = temp_head;
    return (1);
}

int swap_a_bouns(t_stack **a)
{
    t_stack *temp_head;

    if (a == NULL || is_empty_or_unary(*a))
        return (0);
    temp_head = (*a) -> next;
    (*a) -> next = ((*a) -> next) -> next;
    temp_head -> next = *a;
    *a  = temp_head;
    return (1);
}

int ss_bouns(t_stack *a, t_stack *b)
{
    if (!swap_a(&a, NULL) || !swap_b(&b, NULL))
        return (0);
    return (1);
}

int push_a_bouns(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*b == NULL || b == NULL)
        return (0);
    temp = (*b) ->next;
    ft_lstadd_front2(a, *b);
    *b = temp;
    return (1);
}

#include "push_swap.h"

int push_b_bouns(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*a == NULL || a == NULL)
        return (0);
    temp = (*a) ->next;
    ft_lstadd_front2(b, *a, NULL);
    *a = temp;
    return (1);
}

int rotate_bouns(t_stack **a)//momken adeef ft_printf
{
    t_stack *temp;

    if (a == NULL || is_empty_or_unary(*a))
        return (0);
   temp = (*a)-> next;
   ft_lstlast2(*a) ->next = *a;
   (*a) -> next = NULL;
   *a = temp;
    return (1);
}

int reverse_rotate_bouns(t_stack **a)
{
    t_stack *temp;
    t_stack *head;
    t_stack *temp_tail;

    if (a == NULL || is_empty_or_unary(*a))
        return (0);
    head = *a;
    temp_tail = ft_lstlast2(*a);
    while (((*a) -> next) -> next)
        (*a) = (*a)->next;
    temp = *a;
    ft_lstlast2(*a) -> next = head;
    temp -> next = NULL;
    *a = temp_tail;
    return (1);
}
int rr_bouns(t_stack **a, t_stack **b)
{
    if (!rotate_bouns(a) || !rotate_bouns(b))
        return (0);
    return (1);
}

int rrr_bouns(t_stack **a, t_stack **b)
{
    if (!reverse_rotate_bouns(a) || !reverse_rotate_bouns(b))
        return (0);
    return (1);
}
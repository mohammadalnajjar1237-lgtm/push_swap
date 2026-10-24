#include "push_swap.h"

int push_b(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*a == NULL)
        return (0);
    temp = (*a) ->next;
    ft_lstadd_front2(b, *a);
    *a = temp;
    return (1);
}

int rotate(t_stack **a, char c)//momken adeef ft_printf
{
    t_stack *temp;

    if (a == NULL || is_empty_or_unary(*a))
        return (0);
   temp = (*a)-> next;
   ft_lstlast2(*a) ->next = *a;
   (*a) -> next = NULL;
   *a = temp;
    //ft_printf("r%c\n", c);
    return (1);
}

int reverse_rotate(t_stack **a, char c)
{
    t_stack *temp;

    if (a == NULL || is_empty_or_unary(*a))
        return (0);
    temp = (*a) ->next;
    ft_lstlast2(*a) -> next = *a;
    (*a) -> next = NULL;
    *a = temp;
    //ft_printf("rr%c\n", c);
    return (1);
}
int rr(t_stack **a, t_stack **b)
{
    if (!rotate(a, 'a') || !rotate(b, 'b'))
        return (0);
    return (1);
}

int rrr(t_stack **a, t_stack **b)
{
    if (!reverse_rotate(a, 'a') || !reverse_rotate(b, 'b'))
        return (0);
    return (1);
}
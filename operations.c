#include "push_swap.h"

int is_empty_or_unary(t_stack *a)
{
    if (a == NULL || a -> next == NULL)
        return (1);
    return (0);
}

int swap_b(t_stack *b)
{
    t_stack *temp;

    if (is_empty_or_unary(b))
        return (0);
    while (((b->next) ->next)->next)
        b = b->next;
    temp = b -> next;
    b -> next = ft_lstlast2(b);
    (b->next) -> next = temp;
    (temp) -> next = NULL;
    return (1);
}

int swap_a(t_stack *a)
{
    t_stack *temp;

    if (is_empty_or_unary(a))
        return (0);
    while (((a->next) ->next)->next)
        a = a->next;
    temp = a -> next;
    a -> next = ft_lstlast2(a);
    (a->next) -> next = temp;
    (temp) -> next = NULL;
    return (1);
}

int ss(t_stack *a, t_stack *b)
{
    if (!swap_a(a) || !swap_b(b))
        return (0);
    return (1);
}

int push_a(t_stack *a, t_stack *b)
{
    if (b == NULL)
        return (0);
    ft_lstadd_back2(&a, ft_lstlast2(b));
    while ((b->next)->next)
        b = b->next;
    b -> next = NULL;
    return (1);
}

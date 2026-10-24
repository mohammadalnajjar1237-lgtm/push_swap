#include "push_swap.h"

int push_b(t_stack *a, t_stack *b)
{
    if (a == NULL)
        return (0);
    ft_lstadd_back2(&b, ft_lstlast2(a));
    while ((a->next)->next)
        a = a->next;
    a -> next = NULL;
    return (1);
}

int rotate_a(t_stack **a)//momken adeef ft_printf
{
    t_stack *temp_last_node;
    t_stack *temp;

    temp = *a;
    temp_last_node = ft_lstlast2(temp);
    if (is_empty_or_unary(temp))
        return (0);
    while (((temp)->next) -> next)
        temp = (temp) -> next;
    (temp) -> next = NULL;
    temp_last_node -> next = *a;
    *a = temp_last_node;
    return (1);
}

int reverse_rotate_a(t_stack **a)
{
    t_stack *temp;

    if (is_empty_or_unary(*a))
        return (0);
    temp = (*a) ->next;
    ft_lstlast2(*a) -> next = *a;
    (*a) -> next = NULL;
    *a = temp;
    return (1);
}
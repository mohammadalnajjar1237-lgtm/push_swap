#include "push_swap.h"

int reverse_rotate_a(t_stack **a, int *ops_count)
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
    //ft_printf("rr%c\n", c);
    if (ops_count)
    {
        write(1, "rra\n", 4);
        ops_count[8] += 1;
    }
    return (1);
}

int reverse_rotate_b(t_stack **a, int *ops_count)
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
    //ft_printf("rr%c\n", c);
    if (ops_count)
    {
        write(1, "rrb\n", 4);
        ops_count[9] += 1;
    }
    return (1);
}

int rrr(t_stack **a, t_stack **b, int *ops_count)
{
    if (!reverse_rotate_a(a, NULL) || !reverse_rotate_b(b, NULL))
        return (0);
    if (ops_count)
        ops_count[10] += 1;
    write(1, "rrr\n", 4);
    return (1);
}

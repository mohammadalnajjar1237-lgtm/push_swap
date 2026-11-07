#include "push_swap.h"
#include <stdio.h>
int push_b(t_stack **a, t_stack **b, int *ops_count)
{
    t_stack *temp;

    if (*a == NULL || a == NULL)
        return (0);
    temp = (*a) ->next;
    ft_lstadd_front2(b, *a);
    *a = temp;
    ft_printf("pb\n");
     if (ops_count)
        ops_count[4] += 1;
    return (1);
}

int rotate(t_stack **a, char c, int *ops_count)//momken adeef ft_printf
{
    t_stack *temp;

    if (a == NULL || is_empty_or_unary(*a))
        return (0);
   temp = (*a)-> next;
   ft_lstlast2(*a) ->next = *a;
   (*a) -> next = NULL;
   *a = temp;
    ft_printf("r%c\n", c);
     if (ops_count)
     {
        if (c == 'a')
            ops_count[5] += 1;
        else
            ops_count[6] += 1;
     }
    return (1);
}

int reverse_rotate(t_stack **a, char c, int *ops_count)
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
    ft_printf("rr%c\n", c);
    if (ops_count)
     {
        if (c == 'a')
            ops_count[8] += 1;
        else
            ops_count[9] += 1;
     }
    return (1);
}
int rr(t_stack **a, t_stack **b, int *ops_count)
{
    if (!rotate(a, 'a', NULL) || !rotate(b, 'b', NULL))
        return (0);
     if (ops_count)
        ops_count[7] += 1;
    return (1);
}

int rrr(t_stack **a, t_stack **b, int *ops_count)
{
    if (!reverse_rotate(a, 'a', NULL) || !reverse_rotate(b, 'b', NULL))
        return (0);
    if (ops_count)
        ops_count[10] += 1;
    return (1);
}
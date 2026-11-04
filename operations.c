#include "push_swap.h"
#include <stdio.h>
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
    printf("sb\n");//khaleha ft_printf
    if (ops_count)
        ops_count[1] += 1;
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
    printf("sa\n");//khaleha ft_printf
    if (ops_count)
        ops_count[0] += 1;
    return (1);
}

int ss(t_stack *a, t_stack *b,int *ops_count)
{
    if (!swap_a(&a, NULL) || !swap_b(&b, NULL))
        return (0);
    printf("ss\n");//ft
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
    ft_lstadd_front2(a, *b);
    *b = temp;
    printf("pa\n");
     if (ops_count)
        ops_count[3] += 1;
    return (1);
}

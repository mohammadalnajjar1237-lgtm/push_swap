#include "push_swap.h"

void index_stack(t_stack **a)
{
    t_stack *current;
    t_stack *compare;
    int rank;

    current = *a;
    while (current)
    {
        rank = 0;
        compare = *a;
        while (compare)
        {
            if (current->value > compare->value)
                rank++;
            compare = compare->next;
        }
        current->index = rank;
        current = current->next;
    }
}

static int count_bits(int n)
{
    int bits = 0;
    while (n > 0)
    {
        bits++;
        n >>= 1;
    }
    return (bits);
}

static void radix_pass(t_stack **a, t_stack **b, int bit)
{
    int n = stack_size(*a);
    int i = 0;

    while (i < n)
    {
        if ((((*a)->index >> bit) & 1) == 0)
            push_b(a, b);
        else
            rotate(a, 'a');
        i++;
    }
    while (*b)
        push_a(a, b);
}

void sort_complex(t_stack **a, t_stack **b)
{
    int max_bits;
    int bit;
    int size;

    if (stack_is_sorted(*a))
        return;
    index_stack(a);
    size = stack_size(*a);
    max_bits = count_bits(size - 1);
    bit = 0;
    while (bit < max_bits)
    {
        radix_pass(a, b, bit);
        bit++;
    }
}
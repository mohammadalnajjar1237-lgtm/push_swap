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

static int *radix_pass(t_stack **a, t_stack **b, int bit, int *ops_count)
{
    int i = 0;
    int size;

    size = stack_size(*a);
    while (i < size)
    {
        if ((((*a)->index >> bit) & 1) == 0)
            push_b(a, b, ops_count);
        else
            rotate_a(a, ops_count);
        i++;
    }
    while (*b)
        push_a(a, b, ops_count);
    return (ops_count);
}

void sort_complex(t_stack **a, int size, int bench_flag)
{
    int max_bits;
    int bit;
    int *ops_count;
    int disorder;
    t_stack *b;

    ops_count = NULL;
    init_ops(&ops_count);
    if (!ops_count)
		return ;
    disorder = compute_disorder(*a) * 10000;
    b = NULL;
	if (disorder == 0)
    {
		end_sort(ops_count, disorder, bench_flag, "Complex / O(nlog(n))");
        return ;
    }
	index_stack(a);
	max_bits = count_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
		radix_pass(a, &b, bit++, ops_count);
	end_sort(ops_count, disorder, bench_flag, "Complex / O(nlog(n))");
}
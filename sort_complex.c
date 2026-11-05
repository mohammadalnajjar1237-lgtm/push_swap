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

/*static int count_bits(int n)
{
    int bits = 0;
    while (n > 0)
    {
        bits++;
        n >>= 1;
    }
    return (bits);
}*/

static int *radix_pass(t_stack **a, t_stack **b, int bit, int size)
{
    int i = 0;
    static int *ops_count;

    if (!ops_count)
    {
        ops_count = malloc(11  * sizeof(int));
        ft_bzero(ops_count, 11 * sizeof(int));
    }
    if (!ops_count)
        exit(1);//shoof itha exit wela return
    
    while (i < size)
    {
        if ((((*a)->index >> bit) & 1) == 0)
            push_b(a, b, ops_count);
        else
            rotate(a, 'a', ops_count);
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
    disorder = compute_disorder(*a) * 10000;
    b = NULL;
	if (disorder == 0)
    {
        if (bench_flag)
            bench(ops_count, disorder, "Complex / O(nlog(n))");
        free(ops_count);
	    return ;
    }
    index_stack(a);
    max_bits = size - 1;
    bit = 0;
    while (bit < max_bits)
    {
        ops_count = radix_pass(a, &b, bit, size);
        bit++;
    }
    if (bench_flag)
        bench(ops_count, disorder, "Complex / O(nlog(n))");
    free(ops_count);
}
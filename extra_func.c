#include "push_swap.h"

static void print_ops_and_total(int *ops_count)
{
    int i = 0;
    int sum = 0;

    while (i < 11)
        sum += ops_count[i++];
    ft_printf("[bench] total_ops: %d\n", sum);
    ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", ops_count[0], ops_count[1], ops_count[2], ops_count[3], ops_count[4]);
    ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", ops_count[5], ops_count[6], ops_count[7], ops_count[8], ops_count[9], ops_count[10]);
}

void    bench(int *ops_count, int disorder, char *strategy)
{
    ft_printf("[bench] disorder: %f%%\n", disorder);
    ft_printf("[bench] strategy: %s\n", strategy);
    print_ops_and_total(ops_count);
    free(ops_count);
}

void    print_error()
{
    write(2, "ERROR\n", 6);
    exit(1);
}

double compute_disorder(t_stack *a, int size)
{
    double mistakes = 0;
    int total_pairs = 0;
    t_stack *temp;
    while ((a->next))
    {
        total_pairs += 1;
        temp = a  ->next;   
        while (temp)
        {
            if (a ->value > temp->value)
                mistakes += 1;
            temp = temp -> next;
        }
        a = a-> next;
    }
    total_pairs++;
    return (mistakes / total_pairs);
}
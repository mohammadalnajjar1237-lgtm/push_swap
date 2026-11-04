#include "push_swap.h"

static int ft_sqrt(int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (i * i > size || i * i == size)
            return (i);
        i++;
    }
    return (0);
}

static void fill_array_stack(t_stack **chunks, t_stack *a, int sqrt)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (a)
    {
        if (j == 0)
            chucks[i] = create_stack(a -> value);
        else
            ft_lstadd_front2(&chunks[i], create_stack(a -> value));
        if (j == sqrt - 1)
        {
            j = 0;
            i++;
            a = a-> next;
            continue ;
        }
        a = a->next;
        j++;
    }
}

void    sort_medium(t_stack *a, t_stack *b, int size, int bench_flag)
{
    t_stack **chunks;
    int sqrt;

    sqrt = ft_sqrt(size);
    chunks = malloc(sizeof(t_stack *) * sqrt);
    if (!chunck)
        exit(1);//make sure wether to use return or exit
    fill_array_stacks(chuncks, a, sqrt);
}
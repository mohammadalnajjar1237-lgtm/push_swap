#include "push_swap.h"

int main(int av, char **args)
{
    t_stack *a;
    t_stack *b;
    char *temp;
    float disorder;

    b = NULL;
    if (av == 1)
        print_error();
    int size = fill_stack(args, &a, av, 0);
    temp = get_next_line(0);
    while (temp)
    {
        if (ft_strncmp(temp, "sa\n", 4) == 0)
            swap_a_bouns(&a);
        else if (ft_strncmp(temp, "sb\n", 4) == 0)
            swap_b_bouns(&b);
        else if (ft_strncmp(temp, "ss\n", 4) == 0)
            ss_bouns(a, b);
        else if (ft_strncmp(temp, "pa\n", 4) == 0)
            push_a_bouns(&a, &b);
        else if (ft_strncmp(temp, "pb\n", 4) == 0)
            push_b_bouns(&a, &b);
        else if (ft_strncmp(temp, "ra\n", 4) == 0)
            rotate_bouns(&a);
        else if (ft_strncmp(temp, "rb\n", 4) == 0)
            rotate_bouns(&b);
        else if (ft_strncmp(temp, "rr\n", 4) == 0)
            rr_bouns(&a, &b);
        else if (ft_strncmp(temp, "rra\n", 5) == 0)
            reverse_rotate_bouns(&a);
        else if (ft_strncmp(temp, "rrb\n", 5) == 0)
            reverse_rotate_bouns(&b);
        else if (ft_strncmp(temp, "rrr\n", 5) == 0)
            rrr_bouns(&a, &b);
        else
        {
            write(2, "Error\n", 6);
            exit(1);
        }
    }
    disorder = compute_disorder(a, size);
    if (disorder == 0.0 && b == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    return (0);
}
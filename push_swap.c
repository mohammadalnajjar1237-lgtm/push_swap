#include "push_swap.h"


void	push_swap(int bench_flag, char *selector, char **integers, int av)
{
    t_stack *a;
    int selector_flag;

    selector_flag = 1;
    if (*selector == '\0')
        selector_flag = 0;
    if (av == bench_flag + selector_flag + 1)
        print_error();
    fill_stack(integers, &a, av, selector_flag + bench_flag);
    /*if (ft_strncmp(selector, "complex", 7) == 0)
        sort_in_complex(a, bench_flag);
   else if (ft_strncmp(selector, "simple", 6) == 0)
         sort_in_simple(a, bench_flag);
    else if (ft_strncmp(selector, "medium", 6) == 0)
         sort_in_medium(a, bench_flag);
    else
        sort_adaptivly(a, bench_flag);*/
   //3ashan a7el moshkelet el operations bel bench ba3mel one dim array
}

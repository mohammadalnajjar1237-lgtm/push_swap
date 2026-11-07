#include "push_swap.h"

static void split_flags(char **integers, char **selector, int *bench_flag)
{
    if (ft_strnstr(integers[1], "--bench", 9) != NULL || ft_strnstr(integers[2], "--bench", 9) != NULL)
        *bench_flag = 1;
    else
        *bench_flag = 0;
    if (ft_strnstr(integers[1], "--complex", 10) != NULL || ft_strnstr(integers[2], "--complex", 10) != NULL)
        *selector = "--complex";
    else if (ft_strnstr(integers[1], "--simple", 10) != NULL || ft_strnstr(integers[2], "--simple", 10) != NULL)
        *selector = "--simple";
    else if (ft_strnstr(integers[1], "--medium", 9) != NULL || ft_strnstr(integers[2], "--medium", 9) != NULL)
        *selector = "--medium";
    else
        *selector = "";
}

void	push_swap(char **integers, int av, t_stack **a)
{
    char *selector;
    int selector_flag;
    int count;
    int bench_flag = 0;

    selector_flag = 1;
    selector = NULL;
    split_flags(integers, &selector, &bench_flag);
    if (selector[0] == '\0')
        selector_flag = 0;
    if (av <= bench_flag + selector_flag + 1)
        print_error();
   count = fill_stack(integers, a, av, selector_flag + bench_flag);
    if (ft_strncmp(selector, "--complex", 10) == 0)
        sort_complex(a, count, bench_flag);
   else if (ft_strncmp(selector, "--simple", 9) == 0)
         sort_simple(a, count, bench_flag);
    else if (ft_strncmp(selector, "--medium", 9) == 0)
         sort_medium(a, count, bench_flag);
    else
        sort_adaptivly(a, count, bench_flag);
}

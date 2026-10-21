#include <unistd.h>

/*size_t return_number(int bench_flag, int selector_flag, int num_args)
{
    size_t count;
    int start_index;
    int i;
    int j;

    start_index = bench_flag + selector_flag + 1;
    i = 0;
    while 
}*/

void	push_swap(int bench_flag, char *selector, int *integers, int capacity)
{
    stack *a;
    if (!check_args)
    {
        write(2, "ERROR\n", 6);
        exit(1) ;
    }
    a = creat_stack(num_args, integers);
    if (!a)
        exit(1);
    if (ft_strncmp(selector, "complex") == 0)
        sort_in_complex(integers, num_args, bench_flag);
   else if (ft_strncmp(selector, "simple") == 0)
         sort_in_simple(integers, num_args, bench_flag);
    else if (ft_strncmp(selector, "medium") == 0)
         sort_in_medium(integers, num_args, bench_flag);
    else
        sort_adaptivly(integers num_args, bench_flag);
   //3ashan a7el moshkelet el operations bel bench ba3mel two dim array
}

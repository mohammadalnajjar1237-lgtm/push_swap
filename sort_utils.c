#include "push_swap.h"

int stack_size(t_stack *a)
{
	int i = 0;

	while (a)
	{
		a = a->next;
		i++;
	}
	return(i);
}

void init_ops(int **ops_count)
{
	*ops_count = malloc(11  * sizeof(int));
    if (!(*ops_count))
        exit(1);//shoof itha exit wela return
    ft_bzero(*ops_count, 11 * sizeof(int));
}

void	end_sort(int *ops, int disorder, int bench_flag, char *name)
{
	if (bench_flag)
		bench(ops, disorder, name);
	free(ops);
}


void	rotate_to_top(t_stack **s, char c, int pos, int *ops)
{
	int	size;

	size = stack_size(*s);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate(s, c, ops);
	}
	else
	{
		while (pos++ < size)
			reverse_rotate(s, c, ops);
	}
}

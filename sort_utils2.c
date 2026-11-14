#include "push_swap.h"

void init_ops(int **ops_count)
{
	*ops_count = malloc(11  * sizeof(int));
    if (!(*ops_count))
        return ;
    ft_bzero(*ops_count, 11 * sizeof(int));
}

void	sort_three(t_stack **a, int *ops_count, int disorder)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (disorder == 0)
		return ;
	if (first > second && second < third && first < third)
		swap_a(a, ops_count);
	else if (first > second && second > third)
	{
		swap_a(a, ops_count);
		reverse_rotate_a(a, ops_count);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a, ops_count);
	else if (first < second && second > third && first < third)
	{
		swap_a(a, ops_count);
		rotate_a(a, ops_count);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a, ops_count);
}

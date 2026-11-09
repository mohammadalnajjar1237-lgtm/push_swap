#include "push_swap.h"
#include <stdio.h>
static int	find_min_position(t_stack *stack, int size)
{
	t_stack	*current;
	int		min_val;
	int		min_pos;
	int		i;

	current = stack;
	min_val = current->value;
	min_pos = 0;
	i = 0;
	while (i < size)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

static void	sort_three(t_stack **a, int *ops_count)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
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

static void	selection_sort(t_stack **a, t_stack **b, int size, int *ops)
{
	while (size > 3)
	{
		rotate_to_top(a, 'a', find_min_position(*a, size), ops);
		push_b(a, b, ops);
		size--;
	}
	sort_three(a, ops);
	while (*b)
		push_a(a, b, ops);
}



void	sort_simple(t_stack **a, int size, int bench_flag)
{
	int *ops_count;
	int disorder;
	t_stack *b;

	b = NULL;
	ops_count = NULL;
	init_ops(&ops_count);
	if (!ops_count)
		return ;
	disorder = compute_disorder(*a) * 10000;
	if  (disorder == 0)
	{
		end_sort(ops_count, disorder, bench_flag, "Simple / O(n^2)");
		return ;
	}
	if (size == 2)
		swap_a(a, ops_count);
	else if (disorder != 0)
		selection_sort(a, &b, size, ops_count);
	end_sort(ops_count, disorder, bench_flag, "Simple / O(n^2)");
}

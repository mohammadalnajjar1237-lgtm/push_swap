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

static void	rotate_min_to_top(t_stack **a, int pos, int size, int *ops_count)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate(a, 'a', ops_count);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			reverse_rotate(a, 'a', ops_count);
			pos--;
		}
	}
}

static void	sort_two(t_stack **a, int *ops_count)
{
	if ((*a)->value > (*a)->next->value)
		swap_a(a, ops_count);
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
		reverse_rotate(a, 'a', ops_count);
	}
	else if (first > second && second < third && first > third)
		rotate(a, 'a',ops_count);
	else if (first < second && second > third && first < third)
	{
		swap_a(a, ops_count);
		rotate(a, 'a', ops_count);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a,'a', ops_count);
}

void	sort_simple(t_stack **a, int size, int bench_flag)
{
	int	pos;
	int	push_count;
	int *ops_count;
	int disorder;
	t_stack *b;

	b = NULL;
	ops_count = malloc(11  * sizeof(int));
    if (!ops_count)
        exit(1);//shoof itha exit wela return
    ft_bzero(ops_count, 11 * sizeof(int));
	disorder = compute_disorder(*a) * 10000;
	if  (disorder == 0)
	{
		if (bench_flag)//la tensa t7ot ino print 3al 2 standard error
			bench(ops_count, disorder, "Simple / O(n^2)");
		free(ops_count);
		return ;
	}
	if (size == 2)
	{
		sort_two(a, ops_count);
		if (bench_flag)//la tensa t7ot ino print 3al 2 standard error
			bench(ops_count, disorder, "Simple / O(n^2)");
		free(ops_count);
		return ;
	}
	if (size == 3)
	{
		sort_three(a, ops_count);
		if (bench_flag)//la tensa t7ot ino print 3al 2 standard error
			bench(ops_count, disorder, "Simple / O(n^2)");
		free(ops_count);
		return ;
	}
	push_count = size - 3;
	while (push_count > 0)
	{
		pos = find_min_position(*a, size);
		rotate_min_to_top(a, pos, size, ops_count);
		push_b(a, &b, ops_count);
		size--;
		push_count--;
	}
	sort_three(a, ops_count);
	while (b)
		push_a(a, &b, ops_count);
	if (bench_flag)//la tensa t7ot ino print 3al 2 standard error
		bench(ops_count, disorder, "Simple / O(n^2)");
	free(ops_count);
}

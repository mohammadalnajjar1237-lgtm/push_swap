#include "push_swap.h"

static int	find_min_position(t_stack *stack)
{
	t_stack	*current;
	int		min_val;
	int		min_pos;
	int		i;

	current = stack;
	min_val = current->value;
	min_pos = 0;
	i = 0;
	while (current)
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

static void	rotate_min_to_top(t_stack **a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate(a);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			reverse_rotate(a);
			pos--;
		}
	}
}

static void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		swap_a(*a);
}

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(*a);
	else if (first > second && second > third)
	{
		swap_a(*a);
		reverse_rotate(a);
	}
	else if (first > second && second < third && first > third)
		rotate(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(*a);
		rotate(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a);
}

void	sort_simple(t_stack **a, t_stack **b, int count)
{
	int	pos;
	int	push_count;

	/*if (stack_is_sorted(*a) || count <= 1)
		return ;*/
	if (count == 2)
	{
		sort_two(a);
		return ;
	}
	if (count == 3)
	{
		sort_three(a);
		return ;
	}
	push_count = count - 3;
	while (push_count > 0)
	{
		pos = find_min_position(*a);
		rotate_min_to_top(a, pos, count);
		push_b(*a, *b);
		push_count--;
	}
	sort_three(a);
	while (*b)
		push_a(*a, *b);
}
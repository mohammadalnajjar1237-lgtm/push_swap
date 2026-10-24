#include "push_swap.h"

static int	find_min_position(t_stack *stack, t_stack_track **t)
{
	t_stack	*current;
	int		min_val;
	int		min_pos;
	int		i;

	current = stack;
	(*t)->top = current;
	min_val = current->value;
	min_pos = 0;
	i = 0;
	while (i < (*t)->size)
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

static void	rotate_min_to_top(t_stack *a, int pos,t_stack_track *t)
{
	if (pos <= t->size / 2)
	{
		while (pos > 0)
		{
			rotate(a, 'a');
			pos--;
		}
	}
	else
	{
		pos = t->size - pos;
		while (pos > 0)
		{
			reverse_rotate(a, 'a');
			pos--;
		}
	}
}

static void	sort_two(t_stack *a, t_stack_track *t)
{
	if (a->(t->top)->value > a->(t->top)->next->value)
		swap(a,'a');
}

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		swap(a,'a');
	else if (first > second && second > third)
	{
		swap_a(a);
		reverse_rotate(a, 'a');
	}
	else if (first > second && second < third && first > third)
		rotate(a, 'a');
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate(a, 'a');
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a,'a');
}

void	sort_simple(t_stack *a, t_stack *b, int count)
{
	int	pos;
	int	push_count;
	t_stack_track *t;
	
	t->size = count;
	if (stack_is_sorted(a))
		return ;
	if (t->size == 2)
	{
		sort_two(a);
		return ;
	}
	if (t->size == 3)
	{
		sort_three(a);
		return ;
	}
	push_count = t->size - 3;
	while (push_count > 0)
	{
		pos = find_min_position(a,&t );
		rotate_min_to_top(a, pos,);
		push_b(a, b, 'b');
		push_count--;
	}
	sort_three(a);
	while (b->size > 0)
		push_a(a, b);
}

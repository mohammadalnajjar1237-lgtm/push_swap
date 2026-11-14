/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:29:40 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 11:30:27 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	selection_sort(t_stack **a, t_stack **b, int size, int *ops)
{
	while (size > 3)
	{
		rotate_to_top_simple(a, find_min_position(*a, size), ops);
		push_b(a, b, ops);
		size--;
	}
	sort_three(a, ops, 1);
	while (*b)
		push_a(a, b, ops);
}

void	sort_simple(t_stack **a, int size, int bench_flag)
{
	int		*ops_count;
	int		disorder;
	t_stack	*b;

	b = NULL;
	ops_count = NULL;
	init_ops(&ops_count);
	if (!ops_count)
		return ;
	disorder = compute_disorder(*a) * 10000;
	if (disorder == 0)
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

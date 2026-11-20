/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulja <zabdulja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:47:21 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/20 23:26:27 by zabdulja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ceil_sqrt(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

static int	find_max_position(t_stack *b)
{
	int	max;
	int	pos;
	int	i;

	max = b->index;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int size, int *ops)
{
	int	chunk;
	int	pushed;

	chunk = ceil_sqrt(size) * 3 / 2;
	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			push_b(a, b, ops);
			rotate_b(b, ops);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk)
		{
			push_b(a, b, ops);
			pushed++;
		}
		else
			rotate_a(a, ops);
	}
}

static void	restore_sorted_stack(t_stack **a, t_stack **b, int *ops)
{
	while (*b)
	{
		rotate_to_top(b, 'b', find_max_position(*b), ops);
		push_a(a, b, ops);
	}
}

void	sort_medium(t_stack **a, int size, int bench_flag)
{
	int		*ops;
	int		disorder;
	t_stack	*b;

	b = NULL;
	init_op_counts(&ops);
	if (!ops)
		return ;
	disorder = compute_disorder(*a) * 10000;
	if (size == 3)
	{
		sort_three(a, ops, disorder);
		finish_sort(ops, disorder, bench_flag, "Medium / O(n√n)");
		return ;
	}
	if (disorder != 0)
	{
		assign_ranks(a);
		push_chunks_to_b(a, &b, size, ops);
		restore_sorted_stack(a, &b, ops);
	}
	finish_sort(ops, disorder, bench_flag, "Medium / O(n√n)");
}

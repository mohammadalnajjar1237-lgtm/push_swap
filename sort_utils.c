/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:44:01 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 14:44:02 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
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
		{
			if (c == 'a')
				rotate_a(s, ops);
			else
				rotate_b(s, ops);
		}
	}
	else
	{
		while (pos++ < size)
		{
			if (c == 'a')
				reverse_rotate_a(s, ops);
			else
				reverse_rotate_b(s, ops);
		}
	}
}

void	rotate_to_top_simple(t_stack **s, int pos, int *ops)
{
	while (pos-- > 0)
		rotate_a(s, ops);
}

int	num_pointers(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

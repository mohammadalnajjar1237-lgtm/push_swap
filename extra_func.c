/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:06:18 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 11:09:04 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ops_and_total(int *ops_count)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < 11)
		sum += ops_count[i++];
	ft_printf("[bench] total_ops: %d\n", sum);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", ops_count[0],
		ops_count[1], ops_count[2], ops_count[3], ops_count[4]);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ops_count[5],
		ops_count[6],
		ops_count[7],
		ops_count[8],
		ops_count[9],
		ops_count[10]);
}

void	bench(int *ops_count, int disorder, char *strategy)
{
	ft_printf("[bench] disorder: %f%%\n", disorder);
	ft_printf("[bench] strategy: %s\n", strategy);
	if (ops_count)
		print_ops_and_total(ops_count);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

double	compute_disorder(t_stack *a)
{
	double	mistakes;
	double	total_pairs;
	t_stack	*temp;

	mistakes = 0;
	total_pairs = 0;
	while ((a))
	{
		temp = a->next;
		while (temp)
		{
			total_pairs += 1;
			if (a->value > temp->value)
				mistakes += 1;
			temp = temp->next;
		}
		a = a->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}

void	free_nodes(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
}

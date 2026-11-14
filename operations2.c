/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:13:15 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 11:13:17 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(t_stack **a, t_stack **b, int *ops_count)
{
	t_stack	*temp;

	if (*a == NULL || a == NULL)
		return (0);
	temp = (*a)->next;
	ft_lstadd_front2(b, *a, NULL);
	*a = temp;
	write(1, "pb\n", 3);
	if (ops_count)
		ops_count[4] += 1;
	return (1);
}

int	rotate_a(t_stack **a, int *ops_count)
{
	t_stack	*temp;

	if (a == NULL || is_empty_or_unary(*a))
		return (0);
	temp = (*a)->next;
	ft_lstlast2(*a)->next = *a;
	(*a)->next = NULL;
	*a = temp;
	if (ops_count)
	{
		write(1, "ra\n", 3);
		ops_count[5] += 1;
	}
	return (1);
}

int	rotate_b(t_stack **a, int *ops_count)
{
	t_stack	*temp;

	if (a == NULL || is_empty_or_unary(*a))
		return (0);
	temp = (*a)->next;
	ft_lstlast2(*a)->next = *a;
	(*a)->next = NULL;
	*a = temp;
	if (ops_count)
	{
		write(1, "rb\n", 3);
		ops_count[6] += 1;
	}
	return (1);
}

int	rr(t_stack **a, t_stack **b, int *ops_count)
{
	if (!rotate_a(a, NULL) || !rotate_b(b, NULL))
		return (0);
	if (ops_count)
		ops_count[7] += 1;
	write(1, "rr\n", 3);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:13:40 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/20 23:25:35 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_b_bonus(t_stack **b)
{
	t_stack	*temp_head;

	if (NULL || has_less_than_two(*b))
		return (0);
	temp_head = (*b)->next;
	(*b)->next = ((*b)->next)->next;
	temp_head->next = *b;
	*b = temp_head;
	return (1);
}

int	swap_a_bonus(t_stack **a)
{
	t_stack	*temp_head;

	if (a == NULL || has_less_than_two(*a))
		return (0);
	temp_head = (*a)->next;
	(*a)->next = ((*a)->next)->next;
	temp_head->next = *a;
	*a = temp_head;
	return (1);
}

int	ss_bonus(t_stack **a, t_stack **b)
{
	if (!swap_a_bonus(a) || !swap_b_bonus(b))
		return (0);
	return (1);
}

int	push_a_bonus(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL || b == NULL)
		return (0);
	temp = (*b)->next;
	stack_add_front(a, *b, NULL);
	*b = temp;
	return (1);
}

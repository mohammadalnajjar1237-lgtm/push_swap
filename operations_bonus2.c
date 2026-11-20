/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:13:31 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/20 23:25:34 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b_bonus(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL || a == NULL)
		return (0);
	temp = (*a)->next;
	stack_add_front(b, *a, NULL);
	*a = temp;
	return (1);
}

int	rotate_bonus(t_stack **a)
{
	t_stack	*temp;

	if (a == NULL || has_less_than_two(*a))
		return (0);
	temp = (*a)->next;
	stack_last(*a)->next = *a;
	(*a)->next = NULL;
	*a = temp;
	return (1);
}

int	reverse_rotate_bonus(t_stack **a)
{
	t_stack	*temp;
	t_stack	*head;
	t_stack	*temp_tail;

	if (a == NULL || has_less_than_two(*a))
		return (0);
	head = *a;
	temp_tail = stack_last(*a);
	while (((*a)->next)->next)
		(*a) = (*a)->next;
	temp = *a;
	stack_last(*a)->next = head;
	temp->next = NULL;
	*a = temp_tail;
	return (1);
}

int	rr_bonus(t_stack **a, t_stack **b)
{
	if (!rotate_bonus(a) || !rotate_bonus(b))
		return (0);
	return (1);
}

int	rrr_bonus(t_stack **a, t_stack **b)
{
	if (!reverse_rotate_bonus(a) || !reverse_rotate_bonus(b))
		return (0);
	return (1);
}

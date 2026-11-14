/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:44:28 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 14:44:32 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ops(int **ops_count)
{
	*ops_count = malloc(11 * sizeof(int));
	if (!(*ops_count))
		return ;
	ft_bzero(*ops_count, 11 * sizeof(int));
}

void	sort_three(t_stack **a, int *ops_count, int disorder)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (disorder == 0)
		return ;
	if (first > second && second < third && first < third)
		swap_a(a, ops_count);
	else if (first > second && second > third)
	{
		swap_a(a, ops_count);
		reverse_rotate_a(a, ops_count);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a, ops_count);
	else if (first < second && second > third && first < third)
	{
		swap_a(a, ops_count);
		rotate_a(a, ops_count);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a, ops_count);
}

t_stack	*ft_lstlast2(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

long	turn_to_int(char *nptr, int *i)
{
	long	result;

	result = 0;
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		result = (result * 10) + (nptr[*i] - '0');
		(*i)++;
	}
	return (result);
}

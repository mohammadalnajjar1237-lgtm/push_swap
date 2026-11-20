/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_args_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:49:54 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/20 23:24:28 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(t_stack *a, int n)
{
	t_stack	*temp;
	t_stack	*head;

	head = a;
	while (a)
	{
		temp = a -> next;
		while (temp)
		{
			if (temp -> value == a -> value)
			{
				free_nodes(head);
				print_error();
			}
			temp = temp -> next;
		}
		a = a->next;
	}
	return (n);
}

t_stack	*create_node(int value)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->value = value;
	a->next = NULL;
	return (a);
}

void	stack_add_front(t_stack **lst, t_stack *new, char **integers)
{
	if (lst == NULL)
		return ;
	if (new == NULL)
	{
		free_nodes(*lst);
		free_string_array(integers);
		exit(1);
	}
	new->next = *lst;
	*lst = new;
}

int	fill_stack(char **args, t_stack **a, int av, int flags_num)
{
	char	**integers;
	int		i;
	int		n;

	i = flags_num + 1;
	integers = NULL;
	while (i < av)
	{
		if (args[i][0] == '\0')
		{
			free_string_array(integers);
			print_error();
		}
		integers = merge_string_arrays(ft_split(args[i], ' '), integers);
		i++;
	}
	i = 0;
	while (integers[i])
		i++;
	n = i;
	while (i > 0)
		stack_add_front(a, create_node(parse_integer(integers, *a, --i)),
			integers);
	free_string_array(integers);
	return (check_duplicates(*a, n));
}

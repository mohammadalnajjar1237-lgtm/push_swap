/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:54:41 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/20 23:24:36 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_checker(char *temp, t_stack *a, t_stack *b)
{
	free(temp);
	free_nodes(a);
	free_nodes(b);
	print_error();
}

static void	execute_operation(char *temp, t_stack **a, t_stack **b)
{
	if (ft_strncmp(temp, "sa\n", 4) == 0)
		swap_a_bonus(a);
	else if (ft_strncmp(temp, "sb\n", 4) == 0)
		swap_b_bonus(b);
	else if (ft_strncmp(temp, "ss\n", 4) == 0)
		ss_bonus(a, b);
	else if (ft_strncmp(temp, "pa\n", 4) == 0)
		push_a_bonus(a, b);
	else if (ft_strncmp(temp, "pb\n", 4) == 0)
		push_b_bonus(a, b);
	else if (ft_strncmp(temp, "ra\n", 4) == 0)
		rotate_bonus(a);
	else if (ft_strncmp(temp, "rb\n", 4) == 0)
		rotate_bonus(b);
	else if (ft_strncmp(temp, "rr\n", 4) == 0)
		rr_bonus(a, b);
	else if (ft_strncmp(temp, "rra\n", 5) == 0)
		reverse_rotate_bonus(a);
	else if (ft_strncmp(temp, "rrb\n", 5) == 0)
		reverse_rotate_bonus(b);
	else if (ft_strncmp(temp, "rrr\n", 5) == 0)
		rrr_bonus(a, b);
	else
		exit_checker(temp, *a, *b);
}

int	main(int av, char **args)
{
	t_stack	*a;
	t_stack	*b;
	char	*temp;
	float	disorder;

	b = NULL;
	a = NULL;
	if (av == 1)
		return (0);
	fill_stack(args, &a, av, 0);
	temp = get_next_line(0);
	while (temp)
	{
		execute_operation(temp, &a, &b);
		free(temp);
		temp = get_next_line(0);
	}
	disorder = compute_disorder(a);
	if (disorder == 0.0 && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_nodes(a);
	return (0);
}

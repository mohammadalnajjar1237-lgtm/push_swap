/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:10:46 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/20 23:24:40 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validate_single_arg(char *str)
{
	int	i;

	i = 0;
	while ((str[i] > '0' && str[i] <= '9') || str[i] == ' ')
		i++;
	if (str[i] != '\0')
		print_error();
	exit(0);
}

int	main(int av, char **args)
{
	t_stack	*a;

	a = NULL;
	if (av == 1)
		return (1);
	if (av == 2 && (ft_strncmp(args[1], "--", 2) == 0))
		print_error();
	if (av == 2)
		validate_single_arg(args[1]);
	push_swap(args, av, &a);
	free_nodes(a);
	return (0);
}
